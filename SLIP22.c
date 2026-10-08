//SLIP - 22

//Q1
======================================================================================================================

#include <stdio.h>

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
    FILE *fp, *out;
    int age;
    char name[50];
    int a[100], n = 0;
    int i;

    fp = fopen("employee.txt", "r");

    if(fp == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    while(fscanf(fp, "%s %d", name, &age) == 2)
    {
        a[n] = age;
        n++;
    }

    fclose(fp);

    quickSort(a, 0, n - 1);

    out = fopen("sortedemponage.txt", "w");

    for(i = 0; i < n; i++)
    {
        fprintf(out, "%d\n", a[i]);
    }

    fclose(out);

    printf("Employees sorted by age.\n");
    printf("Data stored in sortedemponage.txt\n");

    return 0;
}

======================================================================================================================
//DBMS
======================================================================================================================

CREATE DATABASE employee_department_db;

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
    FOREIGN KEY(dno) REFERENCES Department(dno),
    CHECK(salary > 5000)
);

INSERT INTO Department VALUES
(1, 'Computer', 'Nanded'),
(2, 'HR', 'Pune'),
(3, 'Sales', 'Mumbai'),
(4, 'IT', 'Nashik');

INSERT INTO Employee VALUES
(101, 'Sagar', 'Clerk', 25000, 1),
(102, 'Amit', 'Developer', 35000, 1),
(103, 'Anita', 'Manager', 45000, 2),
(104, 'Rahul', 'Developer', 30000, 3),
(105, 'Akshay', 'Tester', 28000, 4),
(106, 'Pooja', 'Developer', 40000, 1);

//B) Queries
======================================================================================================================

//i) Change designation of Sagar to Manager

UPDATE Employee
SET designation = 'Manager'
WHERE ename = 'Sagar';

//ii) Find minimum salary

SELECT MIN(salary) AS minimum_salary
FROM Employee;

//iii) Display departments located in Nanded

SELECT *
FROM Department
WHERE location = 'Nanded';

//iv) Display employee names starting with A

SELECT ename
FROM Employee
WHERE ename LIKE 'A%';

//v) Display department number wise employee count

SELECT dno, COUNT(*) AS employee_count
FROM Employee
GROUP BY dno;

======================================================================================================================
//C)

SELECT D.dname, SUM(E.salary) AS total_salary
FROM Department D
JOIN Employee E
ON D.dno = E.dno
GROUP BY D.dname;

======================================================================================================================