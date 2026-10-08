//SLIP - 24

//Q1
======================================================================================================================

#include <stdio.h>

void countingSort(int a[], int n)
{
    int count[100] = {0};
    int output[100];
    int i, j, k = 0;

    for(i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    for(i = 0; i < 100; i++)
    {
        while(count[i] > 0)
        {
            output[k] = i;
            k++;
            count[i]--;
        }
    }

    for(i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    countingSort(a, n);

    printf("\nSorted array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

======================================================================================================================
//DBMS
======================================================================================================================

CREATE DATABASE bus_route_db24;

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
(42, 'Pimpri', 'Vimannagar', 15),
(43, 'Nashik', 'Baramati', 8),
(44, 'Pimpri', 'Vimannagar', 18),
(45, 'Pune', 'Baramati', 2);

INSERT INTO Bus VALUES
(201, 40, 'Sangamner', 41),
(202, 25, 'Pune', 42),
(203, 18, 'Nashik', 43),
(204, 35, 'Sangamner', 44),
(205, 22, 'Pune', 45),
(206, 30, 'Sangamner', 41);

//B) Queries
======================================================================================================================

//i) Count buses at Sangamner depot

SELECT COUNT(*) AS bus_count
FROM Bus
WHERE depot_name = 'Sangamner';

//ii) Delete buses having capacity less than 20

DELETE FROM Bus
WHERE capacity < 20;

//iii) Display buses on route 41

SELECT *
FROM Bus
WHERE Routeno = 41;

//iv) Find route having maximum number of stations

SELECT *
FROM Route
WHERE no_of_stations =
(
    SELECT MAX(no_of_stations)
    FROM Route
);

//v) Display routes from Pimpri to Vimannagar

SELECT *
FROM Route
WHERE source = 'Pimpri'
AND destination = 'Vimannagar';

======================================================================================================================
//C)

DELETE FROM Bus
WHERE Routeno IN
(
    SELECT Routeno
    FROM Route
    WHERE destination = 'Baramati'
);

======================================================================================================================