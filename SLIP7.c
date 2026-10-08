//SLIP - 7   
   
//Q1   
======================================================================================================================   
#include <stdio.h>   
   
int main()   
{   
    int a[100], n, x, i, low, high, mid, position = -1;   
   
    printf("Enter number of elements: ");   
    scanf("%d", &n);   
   
    printf("Enter sorted elements:\n");   
   
    for(i = 0; i < n; i++)   
    {   
        scanf("%d", &a[i]);   
    }   
   
    printf("Enter element to search: ");   
    scanf("%d", &x);   
   
    low = 0;   
    high = n - 1;   
   
    while(low <= high)   
    {   
        mid = (low + high) / 2;   
   
        if(a[mid] == x)   
        {   
            position = mid + 1;   
            break;   
        }   
        else if(x < a[mid])   
        {   
            high = mid - 1;   
        }   
        else   
        {   
            low = mid + 1;   
        }   
    }   
   
    if(position != -1)   
    {   
        printf("Element found at position %d\n", position);   
    }   
    else   
    {   
        printf("Element not found\n");   
    }   
   
    return 0;   
}   
======================================================================================================================   
//DBMS   
======================================================================================================================   
   
CREATE DATABASE item_supplier_db;   
   
CREATE TABLE Item   
(   
    itemno INT PRIMARY KEY,   
    name VARCHAR(50),   
    quantity INT   
);   
   
CREATE TABLE Supplier   
(   
    sno INT PRIMARY KEY,   
    name VARCHAR(50),   
    city VARCHAR(50)   
);   
   
CREATE TABLE Item_Supplier   
(   
    itemno INT,   
    sno INT,   
    rate DECIMAL(10,2),   
    PRIMARY KEY(itemno, sno),   
    FOREIGN KEY(itemno) REFERENCES Item(itemno),   
    FOREIGN KEY(sno) REFERENCES Supplier(sno)   
);   
   
INSERT INTO Item VALUES   
(101, 'Mouse', 50),   
(102, 'Keyboard', 25),   
(103, 'Monitor', 15),   
(104, 'Printer', 8),   
(105, 'Webcam', 5);   
   
INSERT INTO Supplier VALUES   
(1, 'Mahesh', 'Pune'),   
(2, 'Mohan', 'Mumbai'),   
(3, 'Suresh', 'Nashik'),   
(4, 'Ramesh', 'Delhi'),   
(5, 'Amit', 'Pune');   
   
INSERT INTO Item_Supplier VALUES   
(101, 1, 450),   
(101, 2, 430),   
(102, 1, 800),   
(102, 3, 780),   
(103, 2, 9500),   
(104, 4, 12000),   
(105, 5, 1500);   
   
//B) Queries   
======================================================================================================================   
   
//i) Change quantity of Mouse to 80   
   
UPDATE Item   
SET quantity = 80   
WHERE name = 'Mouse';   
   
//ii) List suppliers whose name begins with M   
   
SELECT *   
FROM Supplier   
WHERE name LIKE 'M%';   
   
//iii) Display total count of items   
   
SELECT COUNT(*) AS item_count   
FROM Item;   
   
//iv) List suppliers who do not live in Pune   
   
SELECT name   
FROM Supplier   
WHERE city <> 'Pune';   
   
//v) List items having quantity less than 10   
   
SELECT name   
FROM Item   
WHERE quantity < 10;   
======================================================================================================================   
//C)   
   
SELECT S.name   
FROM Supplier S   
JOIN Item_Supplier ISUP   
ON S.sno = ISUP.sno   
WHERE ISUP.rate =   
(   
    SELECT MIN(rate)   
    FROM Item_Supplier   
);   
======================================================================================================================