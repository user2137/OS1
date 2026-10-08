//SLIP - 1
//Q1
======================================================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[100], n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    srand(time(0));

    printf("Random elements are:\n");

    for(i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }

    for(i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = temp;
    }

    printf("\n\nArray after insertion sort:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

======================================================================================================================
DBMS
======================================================================================================================

CREATE TABLE Room
(
    roomno INT PRIMARY KEY,
    room_name VARCHAR(50),
    room_type VARCHAR(10) CHECK(room_type IN ('AC', 'NonAC')),
    charges DECIMAL(10,2)
);

CREATE TABLE Guest
(
    Guestcode INT PRIMARY KEY,
    Gname VARCHAR(50),
    city VARCHAR(50),
    roomno INT UNIQUE,
    FOREIGN KEY(roomno) REFERENCES Room(roomno)
);

INSERT INTO Room VALUES
(101, 'Deluxe', 'AC', 8000),
(102, 'Standard', 'NonAC', 4500),
(103, 'Premium', 'AC', 12000),
(104, 'Executive', 'NonAC', 11000),
(105, 'Luxury', 'AC', 15000);

INSERT INTO Guest VALUES
(1, 'Rahul', 'Nashik', 101),
(2, 'Amit', 'Pune', 102),
(3, 'Sneha', 'Mumbai', 103),
(4, 'Priya', 'Nashik', 104),
(5, 'Rohan', 'Pune', 105);

//QUERIES
//i) Rooms having charges between 5000 and 10000
SELECT *
FROM Room
WHERE charges BETWEEN 5000 AND 10000;

//ii) Guest names sorted by city
SELECT Gname
FROM Guest
ORDER BY city;

//iii) Minimum room charges
SELECT MIN(charges) AS minimum_charges
FROM Room;

//iv) Increase charges of all AC rooms by 15%
UPDATE Room
SET charges = charges * 1.15
WHERE room_type = 'AC';

//v) NONAC rooms having charges greater than 10000
SELECT room_name, charges
FROM Room
WHERE room_type = 'NonAC'
AND charges > 10000;

======================================================================================================================
//C) Guest having highest-charged room
SELECT G.Gname
FROM Guest G
JOIN Room R
ON G.roomno = R.roomno
WHERE R.charges = (SELECT MAX(charges) FROM Room);