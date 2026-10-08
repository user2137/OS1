//SLIP - 23

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
    newNode->prev = temp;

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

    head = reverseList(head);

    printf("\nReversed linked list:\n");
    display(head);

    return 0;
}

======================================================================================================================
//DBMS
======================================================================================================================

CREATE DATABASE customer_account_db23;

CREATE TABLE Customer
(
    cno INT PRIMARY KEY,
    cust_name VARCHAR(50),
    cust_city VARCHAR(50)
);

CREATE TABLE Account
(
    ano INT PRIMARY KEY,
    acc_type VARCHAR(20)
        CHECK(acc_type IN ('Saving', 'Current')),
    balance DECIMAL(12,2),
    cno INT,
    FOREIGN KEY(cno) REFERENCES Customer(cno)
);

INSERT INTO Customer VALUES
(101, 'Rahul', 'Pune'),
(102, 'Sahil', 'Nashik'),
(103, 'Sachin', 'Mumbai'),
(104, 'Sneha', 'Pune'),
(105, 'Amit', 'Nashik');

INSERT INTO Account VALUES
(1001, 'Saving', 50000, 101),
(1002, 'Current', 75000, 102),
(1003, 'Saving', 120000, 103),
(1004, 'Current', 95000, 104),
(1005, 'Saving', 35000, 102),
(1006, 'Current', 150000, 105);

//B) Queries
======================================================================================================================

//i) Count customers whose name contains "in"

SELECT COUNT(*) AS customer_count
FROM Customer
WHERE cust_name LIKE '%in%';

//ii) Find average balance of Current accounts

SELECT AVG(balance) AS average_balance
FROM Account
WHERE acc_type = 'Current';

//iii) Display account details sorted by balance

SELECT *
FROM Account
ORDER BY balance;

//iv) Increase balance of all accounts of Sahil by 10000

UPDATE Account
SET balance = balance + 10000
WHERE cno =
(
    SELECT cno
    FROM Customer
    WHERE cust_name = 'Sahil'
);

//v) Add phone_no to Customer

ALTER TABLE Customer
ADD phone_no VARCHAR(15);

======================================================================================================================
//C)

SELECT C.cust_city, C.cust_name, A.balance
FROM Customer C
JOIN Account A
ON C.cno = A.cno
WHERE A.balance =
(
    SELECT MIN(A2.balance)
    FROM Account A2
    JOIN Customer C2
    ON A2.cno = C2.cno
    WHERE C2.cust_city = C.cust_city
);

======================================================================================================================