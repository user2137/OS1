//SLIP - 2

//Q1
======================================================================================================================
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front, rear;

void Initialize()
{
    front = -1;
    rear = -1;
}

int IsEmpty()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

void Insert(int x)
{
    if(rear == MAX - 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = x;
    }
}

void Delete()
{
    if(IsEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Deleted element = %d\n", queue[front]);
        front++;

        if(front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void Display()
{
    int i;

    if(IsEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements are:\n");

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

    Initialize();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        Insert(x);
    }

    Display();

    Delete();

    Display();

    return 0;
}
======================================================================================================================
DBMS
======================================================================================================================
CREATE DATABASE company_db;

CREATE TABLE Department
(
    dno INT PRIMARY KEY,
    dname VARCHAR(50),
    location VARCHAR(50)
);
CREATE TABLE Employee
(
    eno INT PRIMARY KEY,
    ename VARCHAR(50),
    designation VARCHAR(50),
    salary DECIMAL(10,2),
    dno INT,
    FOREIGN KEY(dno) REFERENCES Department(dno)
);

INSERT INTO Department VALUES
(1, 'HR', 'Pune'),
(2, 'IT', 'Nashik'),
(3, 'Finance', 'Delhi'),
(4, 'Sales', 'Nashik'),
(5, 'Admin', 'Mumbai');

INSERT INTO Employee VALUES
(101, 'Rohit', 'Manager', 60000, 1),
(102, 'Sneha', 'Developer', 50000, 2),
(103, 'Pooja', 'HR Executive', 45000, 1),
(104, 'Amit', 'Accountant', 40000, 3),
(105, 'Neha', 'Developer', 55000, 2),
(106, 'Kiran', 'Sales Executive', 35000, 4),
(107, 'Priya', 'Manager', 65000, 5);

//B) Queries


//i) Give a 5% raise to all employees

UPDATE Employee
SET salary = salary * 1.05;

//ii) Display average salary
SELECT AVG(salary) AS average_salary
FROM Employee;

//iii) Departments located in Nashik
SELECT *
FROM Department
WHERE location = 'Nashik';

//iv) Employees whose name ends with a
SELECT *
FROM Employee
WHERE ename LIKE '%a';

//v) Display location of HR department
SELECT location
FROM Department
WHERE dname = 'HR';

//C) Employees who do NOT work in departments located at Delhi
SELECT E.*
FROM Employee E
JOIN Department D
ON E.dno = D.dno
WHERE D.location <> 'Delhi';
======================================================================================================================
//C) Guest having highest-charged room

SELECT G.Gname
FROM Guest G
JOIN Room R
ON G.roomno = R.roomno
WHERE R.charges = (SELECT MAX(charges) FROM Room);