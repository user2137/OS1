//SLIP - 10   
   
//Q1   
======================================================================================================================   
#include <stdio.h>   
#include <stdlib.h>   
#include <time.h>   
   
void merge(int a[], int low, int mid, int high)   
{   
    int i, j, k;   
    int b[100];   
   
    i = low;   
    j = mid + 1;   
    k = low;   
   
    while(i <= mid && j <= high)   
    {   
        if(a[i] <= a[j])   
        {   
            b[k] = a[i];   
            i++;   
        }   
        else   
        {   
            b[k] = a[j];   
            j++;   
        }   
   
        k++;   
    }   
   
    while(i <= mid)   
    {   
        b[k] = a[i];   
        i++;   
        k++;   
    }   
   
    while(j <= high)   
    {   
        b[k] = a[j];   
        j++;   
        k++;   
    }   
   
    for(i = low; i <= high; i++)   
    {   
        a[i] = b[i];   
    }   
}   
   
void mergeSort(int a[], int low, int high)   
{   
    int mid;   
   
    if(low < high)   
    {   
        mid = (low + high) / 2;   
   
        mergeSort(a, low, mid);   
        mergeSort(a, mid + 1, high);   
        merge(a, low, mid, high);   
    }   
}   
   
int main()   
{   
    int a[100], n, i;   
   
    printf("Enter number of elements: ");   
    scanf("%d", &n);   
   
    srand(time(0));   
   
    printf("Random array:\n");   
   
    for(i = 0; i < n; i++)   
    {   
        a[i] = rand() % 100;   
        printf("%d ", a[i]);   
    }   
   
    mergeSort(a, 0, n - 1);   
   
    printf("\n\nSorted array:\n");   
   
    for(i = 0; i < n; i++)   
    {   
        printf("%d ", a[i]);   
    }   
   
    return 0;   
}   
======================================================================================================================   
//DBMS   
======================================================================================================================   
   
CREATE DATABASE account_customer_db;   
   
CREATE TABLE Customer   
(   
    custno INT PRIMARY KEY,   
    cust_name VARCHAR(50),   
    cust_city VARCHAR(50)   
);   
   
CREATE TABLE Account   
(   
    acctno INT PRIMARY KEY,   
    acct_type VARCHAR(20)   
        CHECK(acct_type IN ('saving', 'current')),   
    balance DECIMAL(12,2)   
        CHECK(balance > 0),   
    branch_name VARCHAR(50),   
    custno INT,   
    FOREIGN KEY(custno) REFERENCES Customer(custno)   
);   
   
INSERT INTO Customer VALUES   
(101, 'Rahul', 'Pune'),   
(102, 'Sanjay', 'Mumbai'),   
(103, 'Ramnath', 'Nashik'),   
(104, 'Sneha', 'Pune'),   
(105, 'Amit', 'Delhi');   
   
INSERT INTO Account VALUES   
(1001, 'saving', 8000, 'M.G.Road', 101),   
(1002, 'current', 15000, 'M.G.Road', 102),   
(1003, 'saving', 12000, 'Camp', 103),   
(1004, 'current', 25000, 'Nashik Road', 104),   
(1005, 'saving', 6000, 'M.G.Road', 105),   
(1006, 'saving', 9000, 'Camp', 101);   
   
//B) Queries   
======================================================================================================================   
   
//i) Display saving accounts having balance greater than 5000   
   
SELECT *   
FROM Account   
WHERE acct_type = 'saving'   
AND balance > 5000;   
   
//ii) Count customers in Pune   
   
SELECT COUNT(*) AS customer_count   
FROM Customer   
WHERE cust_city = 'Pune';   
   
//iii) Find total balance at branch M.G.Road   
   
SELECT SUM(balance) AS total_balance   
FROM Account   
WHERE branch_name = 'M.G.Road';   
   
//iv) Delete record whose customer name is Ramnath   
   
DELETE FROM Account   
WHERE custno =   
(   
    SELECT custno   
    FROM Customer   
    WHERE cust_name = 'Ramnath'   
);   
   
DELETE FROM Customer   
WHERE cust_name = 'Ramnath';   
   
//v) Change city of Sanjay to Pune   
   
UPDATE Customer   
SET cust_city = 'Pune'   
WHERE cust_name = 'Sanjay';   
======================================================================================================================   
//C)   
   
SELECT C.cust_city, COUNT(A.acctno) AS account_holders   
FROM Customer C   
JOIN Account A   
ON C.custno = A.custno   
GROUP BY C.cust_city;   
======================================================================================================================