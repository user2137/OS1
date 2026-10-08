//SLIP - 20

//Q1
======================================================================================================================

#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    char name[50];
    int age;
};

void merge(struct Employee emp[], int low, int mid, int high)
{
    struct Employee temp[100];
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(emp[i].age <= emp[j].age)
        {
            temp[k] = emp[i];
            i++;
        }
        else
        {
            temp[k] = emp[j];
            j++;
        }

        k++;
    }

    while(i <= mid)
    {
        temp[k] = emp[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        temp[k] = emp[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++)
    {
        emp[i] = temp[i];
    }
}

void mergeSort(struct Employee emp[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergeSort(emp, low, mid);
        mergeSort(emp, mid + 1, high);

        merge(emp, low, mid, high);
    }
}

int main()
{
    struct Employee emp[100];
    int n, i;
    FILE *fp;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    fp = fopen("employee.txt", "w");

    for(i = 0; i < n; i++)
    {
        printf("\nEnter employee name: ");
        scanf("%s", emp[i].name);

        printf("Enter age: ");
        scanf("%d", &emp[i].age);

        fprintf(fp, "%s %d\n", emp[i].name, emp[i].age);
    }

    fclose(fp);

    mergeSort(emp, 0, n - 1);

    fp = fopen("sortedemponage.txt", "w");

    for(i = 0; i < n; i++)
    {
        fprintf(fp, "%s %d\n", emp[i].name, emp[i].age);
    }

    fclose(fp);

    printf("\nEmployees sorted by age:\n");

    for(i = 0; i < n; i++)
    {
        printf("%s %d\n", emp[i].name, emp[i].age);
    }

    printf("\nSorted data stored in sortedemponage.txt\n");

    return 0;
}

======================================================================================================================
//DBMS
======================================================================================================================

CREATE DATABASE customer_account_db;

CREATE TABLE Customer
(
    cust_no INT PRIMARY KEY,
    cust_name VARCHAR(50),
    cust_city VARCHAR(50)
);

CREATE TABLE Account
(
    acc_no INT PRIMARY KEY,
    acc_type VARCHAR(20)
        CHECK(acc_type IN ('Saving', 'Current')),
    balance DECIMAL(12,2),
    cust_no INT,
    FOREIGN KEY(cust_no) REFERENCES Customer(cust_no)
);

INSERT INTO Customer VALUES
(101, 'Rahul', 'Delhi'),
(102, 'Sneha', 'Pune'),
(103, 'Amit', 'Ahilyanagar'),
(104, 'Pooja', 'Mumbai'),
(105, 'Sahil', 'Pune');

INSERT INTO Account VALUES
(101123, 'Current', 1200000, 101),
(101124, 'Saving', 80000, 102),
(101125, 'Saving', 150000, 103),
(101126, 'Current', 900000, 104),
(101127, 'Current', 1500000, 105),
(101128, 'Saving', 60000, 105);

//B) Queries
======================================================================================================================

//i) Display customers from Delhi

SELECT *
FROM Customer
WHERE cust_city = 'Delhi';

//ii) Find total balance of Saving accounts

SELECT SUM(balance) AS total_balance
FROM Account
WHERE acc_type = 'Saving';

//iii) Find account having maximum balance

SELECT *
FROM Account
WHERE balance =
(
    SELECT MAX(balance)
    FROM Account
);

//iv) Increase balance of account 101123 by 10000

UPDATE Account
SET balance = balance + 10000
WHERE acc_no = 101123;

//v) Add AADHAR number to Customer

ALTER TABLE Customer
ADD AADHAR VARCHAR(20);

======================================================================================================================
//C)

SELECT C.cust_name
FROM Customer C
JOIN Account A
ON C.cust_no = A.cust_no
WHERE A.acc_type = 'Current'
AND A.balance > 1000000;

======================================================================================================================