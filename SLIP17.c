//SLIP - 17

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
        i = low;
        j = high;

        while(i < j)
        {
            while(a[i] <= pivot && i < high)
            {
                i++;
            }

            while(a[j] > pivot)
            {
                j--;
            }

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
//DBMS
======================================================================================================================

CREATE DATABASE property_owner_db;

CREATE TABLE Owner
(
    oname VARCHAR(50) PRIMARY KEY,
    address VARCHAR(100),
    phone VARCHAR(15)
);

CREATE TABLE Property
(
    Pno INT PRIMARY KEY,
    area_Sqft INT,
    location VARCHAR(100),
    city VARCHAR(50),
    oname VARCHAR(50),
    FOREIGN KEY(oname) REFERENCES Owner(oname)
);

INSERT INTO Owner VALUES
('Mr.Rahane', 'Pune', '9876543210'),
('Mr.Baravkar', 'Nashik', '9876543211'),
('Mr.Patil', 'Mumbai', '9876543212'),
('Mr.Sharma', 'Pune', '9876543213'),
('Mr.Kulkarni', 'Nashik', '9876543214');

INSERT INTO Property VALUES
(101, 1500, 'College Road', 'Nashik', 'Mr.Rahane'),
(102, 2500, 'Gangapur Road', 'Nashik', 'Mr.Baravkar'),
(103, 12000, 'Kothrud', 'Pune', 'Mr.Rahane'),
(104, 1800, 'Camp', 'Pune', 'Mr.Patil'),
(105, 11000, 'Kothrud', 'Pune', 'Mr.Sharma'),
(106, 3000, 'Nashik Road', 'Nashik', 'Mr.Baravkar');

//B) Queries
======================================================================================================================

//i) Display properties in Nashik city

SELECT *
FROM Property
WHERE city = 'Nashik';

//ii) Display owners whose property area is greater than 2000 sqft

SELECT DISTINCT O.*
FROM Owner O
JOIN Property P
ON O.oname = P.oname
WHERE P.area_Sqft > 2000;

//iii) Find number of properties owned by Mr.Rahane

SELECT COUNT(*) AS property_count
FROM Property
WHERE oname = 'Mr.Rahane';

//iv) Count properties in Pune

SELECT COUNT(*) AS property_count
FROM Property
WHERE city = 'Pune';

//v) Delete all properties in Pune owned by Mr.Baravkar

DELETE FROM Property
WHERE city = 'Pune'
AND oname = 'Mr.Baravkar';

======================================================================================================================
//C)

SELECT DISTINCT O.*
FROM Owner O
JOIN Property P
ON O.oname = P.oname
WHERE P.city = 'Pune'
AND P.location = 'Kothrud'
AND P.area_Sqft > 10000;

======================================================================================================================