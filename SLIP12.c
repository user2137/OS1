//SLIP - 12

//Q1
======================================================================================================================

#include <stdio.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

int pop()
{
    if(top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    int n, i, x;
    char str[100];
    int flag = 1;

    printf("Enter number of integers: ");
    scanf("%d", &n);

    printf("Enter integers:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    printf("Stack elements in reverse order:\n");

    while(top != -1)
    {
        printf("%d ", pop());
    }

    printf("\n\nEnter a string: ");
    scanf("%s", str);

    top = -1;

    for(i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }

    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] != pop())
        {
            flag = 0;
            break;
        }
    }

    if(flag == 1)
    {
        printf("String is Palindrome\n");
    }
    else
    {
        printf("String is not Palindrome\n");
    }

    return 0;
}

======================================================================================================================
//DBMS
======================================================================================================================

CREATE DATABASE sales_client_db;

CREATE TABLE Client
(
    clientno INT PRIMARY KEY,
    name VARCHAR(50),
    address VARCHAR(100)
);

CREATE TABLE Sales_order
(
    sorderno INT PRIMARY KEY,
    s_order_date DATE,
    order_amt DECIMAL(12,2),
    clientno INT,
    FOREIGN KEY(clientno) REFERENCES Client(clientno),
    CHECK(order_amt > 0)
);

INSERT INTO Client VALUES
(10, 'Rahul', 'Pune'),
(20, 'Sneha', 'Mumbai'),
(30, 'Amit', 'Nagpur'),
(40, 'Pooja', 'Nagpur'),
(50, 'Rohan', 'Nashik');

INSERT INTO Sales_order VALUES
(101, '2024-02-10', 25000, 10),
(102, '2024-02-20', 45000, 10),
(103, '2024-02-22', 30000, 20),
(104, '2024-03-15', 60000, 30),
(105, '2024-01-20', 15000, 40),
(106, '2024-02-23', 75000, 50);

//B) Queries
======================================================================================================================

//i) Update address of all clients from Nagpur to Kolhapur

UPDATE Client
SET address = 'Kolhapur'
WHERE address = 'Nagpur';

//ii) Delete sales orders of client number 30

DELETE FROM Sales_order
WHERE clientno = 30;

//iii) Display sales records before 23/02/2024

SELECT *
FROM Sales_order
WHERE s_order_date < '2024-02-23';

//iv) Find sales order having maximum order amount

SELECT *
FROM Sales_order
WHERE order_amt =
(
    SELECT MAX(order_amt)
    FROM Sales_order
);

//v) Add order_status to Sales_order

ALTER TABLE Sales_order
ADD order_status VARCHAR(20);

======================================================================================================================
//C)

SELECT C.*
FROM Client C
JOIN Sales_order S
ON C.clientno = S.clientno
GROUP BY C.clientno, C.name, C.address
HAVING COUNT(S.sorderno) =
(
    SELECT MAX(order_count)
    FROM
    (
        SELECT COUNT(sorderno) AS order_count
        FROM Sales_order
        GROUP BY clientno
    ) AS T
);

======================================================================================================================