//SLIP - 9   
   
//Q1   
======================================================================================================================   
#include <stdio.h>   
#include <stdlib.h>   
#include <time.h>   
   
int main()   
{   
    int a[100], n, x, i, position = -1;   
   
    printf("Enter number of elements: ");   
    scanf("%d", &n);   
   
    srand(time(0));   
   
    printf("Random array:\n");   
   
    for(i = 0; i < n; i++)   
    {   
        a[i] = rand() % 100;   
        printf("%d ", a[i]);   
    }   
   
    printf("\nEnter element to search: ");   
    scanf("%d", &x);   
   
    for(i = 0; i < n; i++)   
    {   
        if(a[i] == x)   
        {   
            position = i + 1;   
            break;   
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
   
CREATE DATABASE person_area_db2;   
   
CREATE TABLE Area   
(   
    aname VARCHAR(50) PRIMARY KEY,   
    area_type VARCHAR(10)   
        CHECK(area_type IN ('urban', 'rural'))   
);   
   
CREATE TABLE Person   
(   
    pnumber INT PRIMARY KEY,   
    pname VARCHAR(50),   
    birthdate DATE,   
    income DECIMAL(10,2),   
    aname VARCHAR(50),   
    FOREIGN KEY(aname) REFERENCES Area(aname)   
);   
   
INSERT INTO Area VALUES   
('Pune', 'urban'),   
('Mumbai', 'urban'),   
('Nashik', 'urban'),   
('Camp', 'urban'),   
('Kalyaninagar', 'rural'),   
('Pashan', 'rural');   
   
INSERT INTO Person VALUES   
(101, 'Rahul', '2001-02-15', 25000, 'Pune'),   
(102, 'Sneha', '2002-03-10', 18000, 'Mumbai'),   
(103, 'Rohan', '2000-02-20', 30000, 'Nashik'),   
(104, 'Amit', '2003-07-12', 12000, 'Camp'),   
(105, 'Priya', '2001-11-05', 22000, 'Kalyaninagar'),   
(106, 'Ravi', '2002-02-18', 15000, 'Pashan'),   
(107, 'Neha', '2000-05-25', 28000, 'Pune');   
   
//B) Queries   
======================================================================================================================   
   
//i) List details of persons with income greater than 10000   
   
SELECT *   
FROM Person   
WHERE income > 10000;   
   
//ii) Transfer all people living in Pune to Delhi   
   
UPDATE Person   
SET aname = 'Delhi'   
WHERE aname = 'Pune';   
   
//iii) Count number of areas of urban type   
   
SELECT COUNT(*) AS urban_area_count   
FROM Area   
WHERE area_type = 'urban';   
   
//iv) Count people born in February   
   
SELECT COUNT(*) AS february_count   
FROM Person   
WHERE EXTRACT(MONTH FROM birthdate) = 2;   
   
//v) List names of all people living in rural area   
   
SELECT P.pname   
FROM Person P   
JOIN Area A   
ON P.aname = A.aname   
WHERE A.area_type = 'rural';   
======================================================================================================================   
//C)   
   
SELECT COUNT(*) AS person_count   
FROM Person   
JOIN Area   
ON Person.aname = Area.aname   
WHERE Area.area_type = 'urban'   
AND Person.income =   
(   
    SELECT AVG(income)   
    FROM Person   
);   
======================================================================================================================