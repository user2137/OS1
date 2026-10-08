//SLIP - 16

//Q1
======================================================================================================================

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
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

struct Node *reverseList(struct Node *head)
{
    struct Node *temp = NULL;
    struct Node *current = head;

    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if(temp != NULL)
    {
        head = temp->prev;
    }

    return head;
}

struct Node *insertEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;

    if(head == NULL)
    {
        return newNode;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct Node *mergeLists(struct Node *head1, struct Node *head2)
{
    struct Node *temp = head1;

    if(head1 == NULL)
    {
        return head2;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head2;

    if(head2 != NULL)
    {
        head2->prev = temp;
    }

    return head1;
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    int n, i, x;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head1 = insertEnd(head1, x);
    }

    printf("First linked list:\n");
    display(head1);

    printf("\nReversed linked list:\n");
    head1 = reverseList(head1);
    display(head1);

    printf("\nEnter element to concatenate with first list: ");
    scanf("%d", &x);

    head1 = insertEnd(head1, x);

    printf("List after concatenation:\n");
    display(head1);

    printf("\nEnter number of elements in second list: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head2 = insertEnd(head2, x);
    }

    printf("Second linked list:\n");
    display(head2);

    head1 = mergeLists(head1, head2);

    printf("\nMerged linked list:\n");
    display(head1);

    return 0;
}

======================================================================================================================
//DBMS
======================================================================================================================

CREATE DATABASE student_teacher_db;

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
    experience INT
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
(2, 'Sneha', 'SY', 'Nashik'),
(3, 'Amit', 'SY', 'Mumbai'),
(4, 'Pooja', 'TY', 'Pune'),
(5, 'Rohan', 'TY', 'Nashik'),
(6, 'Neha', 'FY', 'Nashik');

INSERT INTO Teacher VALUES
(101, 'Pawar', 8),
(102, 'Sharma', 12),
(103, 'Patil', 6),
(104, 'Joshi', 4),
(105, 'Kulkarni', 10);

INSERT INTO Subject VALUES
(201, 'Data Structure'),
(202, 'DBMS'),
(203, 'Operating System'),
(204, 'Web Technology');

INSERT INTO Student_Teacher VALUES
(1, 101, 201),
(2, 102, 201),
(2, 103, 202),
(3, 101, 203),
(4, 104, 204),
(5, 102, 202),
(6, 105, 201);

//B) Queries
======================================================================================================================

//i) Display teachers having experience greater than 5 years

SELECT *
FROM Teacher
WHERE experience > 5;

//ii) Count students who took Data Structure

SELECT COUNT(DISTINCT sno) AS student_count
FROM Student_Teacher ST
JOIN Subject S
ON ST.subno = S.subno
WHERE S.subname = 'Data Structure';

//iii) Display names of all SY students

SELECT sname
FROM Student
WHERE class = 'SY';

//iv) Change experience of Pawar to 20 years

UPDATE Teacher
SET experience = 20
WHERE tname = 'Pawar';

//v) Display class-wise details of students

SELECT class, COUNT(*) AS student_count
FROM Student
GROUP BY class;

======================================================================================================================
//C)

SELECT T.tname, S.subname, STU.sname
FROM Teacher T
JOIN Student_Teacher ST
ON T.tno = ST.tno
JOIN Subject S
ON ST.subno = S.subno
JOIN Student STU
ON ST.sno = STU.sno;

======================================================================================================================