//SLIP - 21

//Q1
======================================================================================================================

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int x)
{
    if(rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = x;
    }
}

void delete()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;

    if(front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements:\n");

        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int n, i, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(x);
    }

    printf("\nQueue before deletion:\n");
    display();

    delete();

    printf("\nQueue after deletion:\n");
    display();

    return 0;
}

======================================================================================================================
//DBMS
======================================================================================================================

CREATE DATABASE bus_driver_db;

CREATE TABLE Bus
(
    bno INT PRIMARY KEY,
    capacity INT,
    depot_name VARCHAR(50)
);

CREATE TABLE Driver
(
    dno INT PRIMARY KEY,
    driver_name VARCHAR(50),
    license_no VARCHAR(30),
    address VARCHAR(100),
    age INT,
    salary DECIMAL(10,2)
);

CREATE TABLE Bus_Driver
(
    bno INT,
    dno INT,
    Date_of_duty DATE,
    PRIMARY KEY(bno, dno, Date_of_duty),
    FOREIGN KEY(bno) REFERENCES Bus(bno),
    FOREIGN KEY(dno) REFERENCES Driver(dno)
);

INSERT INTO Bus VALUES
(101, 40, 'Kothrud Depot'),
(102, 25, 'Swargate Depot'),
(103, 18, 'Pimpri Depot'),
(104, 35, 'Kothrud Depot'),
(105, 30, 'Nashik Depot');

INSERT INTO Driver VALUES
(1, 'Swapnil', 'LIC101', 'Pune', 24, 30000),
(2, 'Suresh', 'LIC102', 'Nashik', 35, 40000),
(3, 'Sachin', 'LIC103', 'Pune', 28, 35000),
(4, 'Amit', 'LIC104', 'Mumbai', 30, 45000),
(5, 'Rahul', 'LIC105', 'Pune', 26, 32000);

INSERT INTO Bus_Driver VALUES
(101, 1, '2009-02-12'),
(104, 2, '2009-02-12'),
(102, 3, '2017-01-15'),
(103, 4, '2017-01-15'),
(105, 5, '2017-01-15');

//B) Queries
======================================================================================================================

//i) Count buses having capacity greater than 20

SELECT COUNT(*) AS bus_count
FROM Bus
WHERE capacity > 20;

//ii) Count drivers on duty on 15/01/2017

SELECT COUNT(DISTINCT dno) AS driver_count
FROM Bus_Driver
WHERE Date_of_duty = '2017-01-15';

//iii) Display license numbers of drivers whose name starts with S

SELECT license_no
FROM Driver
WHERE driver_name LIKE 'S%';

//iv) Find average salary of drivers

SELECT AVG(salary) AS average_salary
FROM Driver;

//v) Display all details of driver Swapnil

SELECT *
FROM Driver
WHERE driver_name = 'Swapnil';

======================================================================================================================
//C)

SELECT DISTINCT D.driver_name
FROM Driver D
JOIN Bus_Driver BD
ON D.dno = BD.dno
JOIN Bus B
ON BD.bno = B.bno
WHERE B.depot_name = 'Kothrud Depot'
AND BD.Date_of_duty = '2009-02-12';

======================================================================================================================