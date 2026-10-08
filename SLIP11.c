//SLIP - 11

//Q1
======================================================================================================================

#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

char pop()
{
    if(top == -1)
    {
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    char str[100];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    for(i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }

    printf("Reversed string: ");

    while(top != -1)
    {
        printf("%c", pop());
    }

    return 0;
}

======================================================================================================================
//DBMS
======================================================================================================================

CREATE DATABASE employee_project_db;

CREATE TABLE Emp
(
    eno INT PRIMARY KEY,
    ename VARCHAR(50),
    salary DECIMAL(10,2)
);

CREATE TABLE Project
(
    pno INT PRIMARY KEY,
    pname VARCHAR(50),
    budget DECIMAL(12,2)
);

CREATE TABLE Emp_Project
(
    eno INT,
    pno INT,
    total_hours INT,
    PRIMARY KEY(eno, pno),
    FOREIGN KEY(eno) REFERENCES Emp(eno),
    FOREIGN KEY(pno) REFERENCES Project(pno)
);

INSERT INTO Emp VALUES
(101, 'Riya', 30000),
(102, 'Sneha', 35000),
(103, 'Amit', 28000),
(104, 'Pooja', 40000),
(105, 'Rahul', 32000);

INSERT INTO Project VALUES
(1, 'Website', 500000),
(2, 'Banking System', 800000),
(3, 'AI Project', 1000000),
(4, 'Mobile App', 600000);

INSERT INTO Emp_Project VALUES
(101, 1, 120),
(101, 2, 80),
(102, 2, 150),
(103, 3, 200),
(104, 3, 110),
(105, 4, 90);

//B) Queries
======================================================================================================================

//i) Find maximum project budget

SELECT MAX(budget) AS maximum_budget
FROM Project;

//ii) Increase salary of all employees by 10%

UPDATE Emp
SET salary = salary + (salary * 10 / 100);

//iii) Count projects having total hours greater than 100

SELECT COUNT(DISTINCT pno) AS project_count
FROM Emp_Project
WHERE total_hours > 100;

//iv) Display employee names ending with 'a'

SELECT ename
FROM Emp
WHERE ename LIKE '%a';

//v) Add contact_number to Employee table

ALTER TABLE Emp
ADD contact_number VARCHAR(15);

======================================================================================================================
//C)

SELECT E.*
FROM Emp E
LEFT JOIN Emp_Project EP
ON E.eno = EP.eno
WHERE EP.eno IS NULL;

======================================================================================================================