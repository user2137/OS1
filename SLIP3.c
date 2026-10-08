//SLIP - 3

//Q1
======================================================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int a[], int low, int high)
{
    int i, j, pivot, temp;

    if(low < high)
    {
        pivot = a[low];

        i = low + 1;
        j = high;

        while(i <= j)
        {
            while(i <= high && a[i] <= pivot)
                i++;

            while(a[j] > pivot)
                j--;

            if(i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[low];
        a[low] = a[j];
        a[j] = temp;

        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
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

    quickSort(a, 0, n - 1);

    printf("\n\nSorted array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
======================================================================================================================
DBMS
======================================================================================================================

CREATE DATABASE person_area_db;

CREATE TABLE Area
(
    aname VARCHAR(50) PRIMARY KEY,
    area_type VARCHAR(10)
        CHECK(area_type IN ('urban', 'rural')),
    pincode INT
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
('Camp', 'urban', 411001),
('Kalyaninagar', 'urban', 411014),
('Shivajinagar', 'urban', 411005),
('Pashan', 'rural', 411021),
('Wagholi', 'rural', 412207);

INSERT INTO Person VALUES
(101, 'Rahul', '2002-07-15', 25000, 'Camp'),
(102, 'Riya', '2001-02-10', 18000, 'Kalyaninagar'),
(103, 'Rohan', '2000-07-25', 35000, 'Shivajinagar'),
(104, 'Amit', '2003-03-12', 12000, 'Pashan'),
(105, 'Sneha', '2001-11-20', 22000, 'Wagholi'),
(106, 'Raj', '2002-07-05', 15000, 'Kalyaninagar'),
(107, 'Ravi', '2000-02-18', 10000, 'Camp');

//B) Queries

//i) People whose name starts with R

SELECT *
FROM Person
WHERE pname LIKE 'R%';

//ii) People whose birthday is in July

SELECT pname, birthdate
FROM Person
WHERE EXTRACT(MONTH FROM birthdate) = 7;

//iii) People sorted by income
SELECT *
FROM Person
ORDER BY income;
SELECT *
FROM Person
ORDER BY income DESC;

//iv) Count of urban areas
SELECT COUNT(*) AS urban_area_count
FROM Area
WHERE area_type = 'urban';

//v) Change Kalyaninagar pincode to 411036
UPDATE Area
SET pincode = 411036
WHERE aname = 'Kalyaninagar';
======================================================================================================================
//C)

SELECT pname
FROM Person
WHERE aname = 'Camp'
AND income < ANY
(
    SELECT income
    FROM Person
    WHERE aname = 'Kalyaninagar'
);