//SLIP - 6  
  
//Q1  
======================================================================================================================  
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
  
int main()  
{  
    int a[100], n, i, j, min, temp;  
  
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
        min = i;  
  
        for(j = i + 1; j < n; j++)  
        {  
            if(a[j] < a[min])  
            {  
                min = j;  
            }  
        }  
  
        temp = a[i];  
        a[i] = a[min];  
        a[min] = temp;  
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
  
CREATE DATABASE student_teacher_db;  
  
CREATE TABLE Student  
(  
    rno INT PRIMARY KEY,  
    name VARCHAR(50),  
    city VARCHAR(50)  
);  
  
CREATE TABLE Teacher  
(  
    tno INT PRIMARY KEY,  
    tname VARCHAR(50),  
    phone_no VARCHAR(15),  
    salary DECIMAL(10,2)  
);  
  
CREATE TABLE Student_Teacher  
(  
    rno INT,  
    tno INT,  
    subject VARCHAR(50),  
    PRIMARY KEY(rno, tno, subject),  
    FOREIGN KEY(rno) REFERENCES Student(rno),  
    FOREIGN KEY(tno) REFERENCES Teacher(tno)  
);  
  
INSERT INTO Student VALUES  
(101, 'Rahul', 'Ahilyanagar'),  
(102, 'Sneha', 'Pune'),  
(103, 'Amit', 'Ahilyanagar'),  
(104, 'Priya', 'Nashik'),  
(105, 'Rohan', 'Mumbai');  
  
INSERT INTO Teacher VALUES  
(1, 'Prof. Patil', '9822131001', 55000),  
(2, 'Prof. Sharma', '9822131002', 45000),  
(3, 'Prof. Joshi', '9822131003', 60000),  
(4, 'Prof. Pawar', '9822131004', 48000),  
(5, 'Prof. Kulkarni', '9822131005', 70000);  
  
INSERT INTO Student_Teacher VALUES  
(101, 1, 'DBMS'),  
(101, 2, 'Maths'),  
(102, 1, 'DBMS'),  
(102, 3, 'Data Structure'),  
(103, 1, 'Maths'),  
(103, 4, 'Java'),  
(104, 3, 'DBMS'),  
(105, 5, 'Data Structure');  
  
//B) Queries  
======================================================================================================================  
  
//i) List names of students from Ahilyanagar  
  
SELECT name  
FROM Student  
WHERE city = 'Ahilyanagar';  
  
//ii) Count teachers whose salary is between 40000 and 60000  
  
SELECT COUNT(*) AS teacher_count  
FROM Teacher  
WHERE salary BETWEEN 40000 AND 60000;  
  
//iii) Change phone number of Prof. Patil  
  
UPDATE Teacher  
SET phone_no = '9822131226'  
WHERE tname = 'Prof. Patil';  
  
//iv) Display teachers in sorted order of name  
  
SELECT *  
FROM Teacher  
ORDER BY tname;  
  
//v) List teachers having salary less than 50000  
  
SELECT tname  
FROM Teacher  
WHERE salary < 50000;  
======================================================================================================================  
//C)  
  
SELECT tname  
FROM Teacher T  
WHERE NOT EXISTS  
(  
    SELECT subject  
    FROM Student_Teacher ST1  
    WHERE ST1.tno =  
    (  
        SELECT tno  
        FROM Teacher  
        WHERE tname = 'Prof. Patil'  
    )  
    AND ST1.subject IN  
    (  
        SELECT subject  
        FROM Student_Teacher ST2  
        WHERE ST2.tno = T.tno  
    )  
);  
