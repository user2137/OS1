//SLIP - 25

//Q1
======================================================================================================================

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

struct Node *insertEnd(struct Node *head, int data)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(data);

    if(head == NULL)
    {
        return newNode;
    }

    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int n, i, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("\nLinked list:\n");
    display(head);

    printf("\nEnter element to concatenate: ");
    scanf("%d", &x);

    head = insertEnd(head, x);

    printf("\nLinked list after concatenation:\n");
    display(head);

    return 0;
}

======================================================================================================================
//DBMS
======================================================================================================================

CREATE DATABASE employee_project_db25;

CREATE TABLE Employee
(
    empno INT PRIMARY KEY,
    emp_name VARCHAR(50),
    city VARCHAR(50),
    designation VARCHAR(50),
    salary DECIMAL(10,2)
);

CREATE TABLE Project
(
    projno INT PRIMARY KEY,
    proj_name VARCHAR(50),
    status VARCHAR(20)
        CHECK(status IN ('Complete', 'In progress')),
    start_date DATE
);

CREATE TABLE Employee_Project
(
    empno INT,
    projno INT,
    PRIMARY KEY(empno, projno),
    FOREIGN KEY(empno) REFERENCES Employee(empno),
    FOREIGN KEY(projno) REFERENCES Project(projno)
);

INSERT INTO Employee VALUES
(101, 'Rahul', 'Pune', 'Developer', 35000),
(102, 'Sneha', 'Nashik', 'Tester', 30000),
(103, 'Amit', 'Mumbai', 'Developer', 40000),
(104, 'Pooja', 'Pune', 'Designer', 32000),
(105, 'Rohan', 'Nashik', 'Developer', 45000),
(106, 'Neha', 'Mumbai', 'Tester', 28000);

INSERT INTO Project VALUES
(10, 'Website', 'In progress', '2025-04-01'),
(20, 'Mobile App', 'Complete', '2024-06-15'),
(105, 'Banking System', 'In progress', '2025-05-10'),
(30, 'Robotics', 'In progress', '2024-10-20');

INSERT INTO Employee_Project VALUES
(101, 10),
(102, 10),
(103, 105),
(104, 105),
(105, 10),
(106, 20);

//B) Queries
======================================================================================================================

//i) Display names of employees working on project 105

SELECT E.emp_name
FROM Employee E
JOIN Employee_Project EP
ON E.empno = EP.empno
WHERE EP.projno = 105;

//ii) Count projects having status In progress

SELECT COUNT(*) AS project_count
FROM Project
WHERE status = 'In progress';

//iii) Change start date of Robotics to 15/12/2022

UPDATE Project
SET start_date = '2022-12-15'
WHERE proj_name = 'Robotics';

//iv) Increase salaries of employees working on project 10 by 5%

UPDATE Employee
SET salary = salary + (salary * 5 / 100)
WHERE empno IN
(
    SELECT empno
    FROM Employee_Project
    WHERE projno = 10
);

//v) Delete completed projects

DELETE FROM Employee_Project
WHERE projno IN
(
    SELECT projno
    FROM Project
    WHERE status = 'Complete'
);

DELETE FROM Project
WHERE status = 'Complete';

======================================================================================================================
//C)

SELECT P.proj_name, COUNT(EP.empno) AS employee_count
FROM Project P
JOIN Employee_Project EP
ON P.projno = EP.projno
GROUP BY P.projno, P.proj_name
HAVING COUNT(EP.empno) > 3;

======================================================================================================================