//SLIP - 13

//Q1
======================================================================================================================

#include <stdio.h>

int main()
{
    int a[100], n, i, x;
    int low, high, mid;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted array elements:\n");

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
            printf("Element found at position %d\n", mid + 1);
            found = 1;
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

    if(found == 0)
    {
        printf("Element not found\n");
    }

    return 0;
}

======================================================================================================================
//DBMS
======================================================================================================================

CREATE DATABASE bus_route_db;

CREATE TABLE Route
(
    Routeno INT PRIMARY KEY,
    source VARCHAR(50),
    destination VARCHAR(50),
    no_of_stations INT
);

CREATE TABLE Bus
(
    Busno INT PRIMARY KEY,
    capacity INT NOT NULL,
    depot_name VARCHAR(50),
    Routeno INT,
    FOREIGN KEY(Routeno) REFERENCES Route(Routeno)
);

INSERT INTO Route VALUES
(41, 'Pune', 'Hadapsar', 12),
(42, 'Pimpri', 'Hadapsar', 15),
(43, 'Pune Station', 'Swargate', 8),
(44, 'Nashik', 'Sangamner', 14),
(45, 'Pimpri', 'Vimannagar', 11);

INSERT INTO Bus VALUES
(201, 40, 'Swargate', 41),
(202, 30, 'Kothrud', 42),
(203, 50, 'Swargate', 43),
(204, 35, 'Sangamner', 44),
(205, 45, 'Kothrud', 45),
(206, 25, 'Swargate', 41);

//B) Queries
======================================================================================================================

//i) Display buses at depot Swargate

SELECT *
FROM Bus
WHERE depot_name = 'Swargate';

//ii) Delete Bus 204

DELETE FROM Bus
WHERE Busno = 204;

//iii) Display buses on route 41

SELECT *
FROM Bus
WHERE Routeno = 41;

//iv) Display routes having more than 10 stations

SELECT *
FROM Route
WHERE no_of_stations > 10;

//v) Display routes starting from Pune station

SELECT *
FROM Route
WHERE source = 'Pune Station';

======================================================================================================================
//C)

DELETE FROM Bus
WHERE Routeno IN
(
    SELECT Routeno
    FROM Route
    WHERE no_of_stations < 3
);

======================================================================================================================