//SLIP - 8   
   
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
   
CREATE DATABASE student_teacher_db2;   
   
CREATE TABLE Student   
(   
    sno INT PRIMARY KEY,   
    s_name VARCHAR(50),   
    s_class VARCHAR(10)   
        CHECK(s_class IN ('FY', 'SY', 'TY'))   
);   
   
CREATE TABLE Teacher   
(   
    tno INT PRIMARY KEY,   
    t_name VARCHAR(50),   
    yrs_experience INT   
);   
   
CREATE TABLE Student_Teacher   
(   
    sno INT,   
    tno INT,   
    subject VARCHAR(50),   
    PRIMARY KEY(sno, tno, subject),   
    FOREIGN KEY(sno) REFERENCES Student(sno),   
    FOREIGN KEY(tno) REFERENCES Teacher(tno)   
);   
   
INSERT INTO Student VALUES   
(101, 'Rahul', 'FY'),   
(102, 'Sneha', 'SY'),   
(103, 'Amit', 'TY'),   
(104, 'Priya', 'SY'),   
(105, 'Rohan', 'TY'),   
(106, 'Neha', 'FY');   
   
INSERT INTO Teacher VALUES   
(1, 'Patil', 8),   
(2, 'Sharma', 12),   
(3, 'Pawar', 6),   
(4, 'Joshi', 15),   
(5, 'Kulkarni', 4);   
   
INSERT INTO Student_Teacher VALUES   
(101, 1, 'Maths'),   
(101, 2, 'English'),   
(102, 1, 'Maths'),   
(102, 3, 'Science'),   
(103, 2, 'Maths'),   
(103, 4, 'Physics'),   
(104, 3, 'Maths'),   
(105, 4, 'Computer'),   
(106, 5, 'English');   
   
//B) Queries   
======================================================================================================================   
   
//i) Give class-wise number of students   
   
SELECT s_class, COUNT(*) AS student_count   
FROM Student   
GROUP BY s_class;   
   
//ii) List all students studying in class TY   
   
SELECT *   
FROM Student   
WHERE s_class = 'TY';   
   
//iii) Count students who have taken subject Maths   
   
SELECT COUNT(DISTINCT sno) AS student_count   
FROM Student_Teacher   
WHERE subject = 'Maths';   
   
//iv) Delete record of student whose sno is 105   
   
DELETE FROM Student_Teacher   
WHERE sno = 105;   
   
DELETE FROM Student   
WHERE sno = 105;   
   
//v) Add designation column in Teacher table   
   
ALTER TABLE Teacher   
ADD COLUMN designation VARCHAR(50);   
======================================================================================================================   
//C)   
   
SELECT T.t_name, ST.subject, COUNT(ST.sno) AS total_students   
FROM Teacher T   
JOIN Student_Teacher ST   
ON T.tno = ST.tno   
GROUP BY T.t_name, ST.subject   
ORDER BY T.t_name;   
======================================================================================================================