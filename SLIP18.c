//SLIP - 18

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

    printf("Random array:\n");

    for(i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

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

CREATE DATABASE student_teacher_db18;

CREATE TABLE Student
(
    sno INT PRIMARY KEY,
    sname VARCHAR(50),
    class VARCHAR(10),
    city VARCHAR(50)
);

CREATE TABLE Teacher
(
    tno INT PRIMARY KEY,
    tname VARCHAR(50),
    phone_no VARCHAR(15),
    salary DECIMAL(10,2)
);

CREATE TABLE Subject
(
    subno INT PRIMARY KEY,
    subname VARCHAR(50)
);

CREATE TABLE Student_Teacher
(
    sno INT,
    tno INT,
    subno INT,
    PRIMARY KEY(sno, tno, subno),
    FOREIGN KEY(sno) REFERENCES Student(sno),
    FOREIGN KEY(tno) REFERENCES Teacher(tno),
    FOREIGN KEY(subno) REFERENCES Subject(subno)
);

INSERT INTO Student VALUES
(1, 'Rahul', 'FY', 'Pune'),
(2, 'Sneha', 'SY', 'Sangamner'),
(3, 'Amit', 'SY', 'Nashik'),
(4, 'Pooja', 'TY', 'Pune'),
(5, 'Rohan', 'TY', 'Sangamner'),
(6, 'Neha', 'FY', 'Mumbai');

INSERT INTO Teacher VALUES
(101, 'Dr.Wani', '9876543210', 50000),
(102, 'Dr.Mulay', '9876543211', 60000),
(103, 'Dr.Patil', '9876543212', 55000),
(104, 'Dr.Sharma', '9876543213', 45000),
(105, 'Dr.Joshi', '9876543214', 70000);

INSERT INTO Subject VALUES
(201, 'Data Structure'),
(202, 'DBMS'),
(203, 'IKS'),
(204, 'Electronics');

INSERT INTO Student_Teacher VALUES
(1, 101, 201),
(2, 102, 202),
(3, 101, 203),
(4, 103, 204),
(5, 101, 201),
(6, 104, 202);

//B) Queries
======================================================================================================================

//i) Display students from Sangamner

SELECT *
FROM Student
WHERE city = 'Sangamner';

//ii) Find maximum teacher salary

SELECT MAX(salary) AS maximum_salary
FROM Teacher;

//iii) Change Dr. Mulay phone number

UPDATE Teacher
SET phone_no = '9834233235'
WHERE tname = 'Dr.Mulay';

//iv) Display teachers sorted by name

SELECT *
FROM Teacher
ORDER BY tname;

//v) Count students who took IKS

SELECT COUNT(DISTINCT sno) AS student_count
FROM Student_Teacher ST
JOIN Subject S
ON ST.subno = S.subno
WHERE S.subname = 'IKS';

======================================================================================================================
//C)

SELECT DISTINCT STU.*
FROM Student STU
JOIN Student_Teacher ST
ON STU.sno = ST.sno
JOIN Teacher T
ON ST.tno = T.tno
WHERE T.tname = 'Dr.Wani';

======================================================================================================================