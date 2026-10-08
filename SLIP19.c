//SLIP - 19

//Q1
======================================================================================================================

#include <stdio.h>

struct Employee
{
    char name[50];
    int age;
};

int main()
{
    struct Employee emp[100], temp;
    int n, i, j;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter employee name: ");
        scanf("%s", emp[i].name);

        printf("Enter age: ");
        scanf("%d", &emp[i].age);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(emp[j].age > emp[j + 1].age)
            {
                temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }

    printf("\nEmployees sorted by age:\n");

    for(i = 0; i < n; i++)
    {
        printf("%s %d\n", emp[i].name, emp[i].age);
    }

    return 0;
}

======================================================================================================================
//DBMS
======================================================================================================================

CREATE DATABASE order_client_db;

CREATE TABLE Client
(
    cno INT PRIMARY KEY,
    name VARCHAR(50),
    address VARCHAR(100)
);

CREATE TABLE Orders
(
    orderno INT PRIMARY KEY,
    s_order_date DATE,
    amount DECIMAL(12,2),
    cno INT,
    FOREIGN KEY(cno) REFERENCES Client(cno),
    CHECK(amount > 0)
);

INSERT INTO Client VALUES
(1, 'Rahul', 'Pune'),
(2, 'Sneha', 'Mumbai'),
(3, 'Amit', 'Nashik'),
(4, 'Pooja', 'Mumbai'),
(5, 'Rohan', 'Delhi');

INSERT INTO Orders VALUES
(101, '2019-04-10', 25000, 1),
(102, '2019-10-15', 45000, 1),
(103, '2019-10-20', 30000, 2),
(104, '2019-05-12', 60000, 3),
(105, '2019-10-05', 15000, 4),
(106, '2019-12-20', 75000, 5);

//B) Queries
======================================================================================================================

//i) Change order date of client 04 to 12/4/19

UPDATE Orders
SET s_order_date = '2019-04-12'
WHERE cno = 4;

//ii) Display orders in October

SELECT *
FROM Orders
WHERE EXTRACT(MONTH FROM s_order_date) = 10;

//iii) Display orders in descending order of amount

SELECT *
FROM Orders
ORDER BY amount DESC;

//iv) Delete all clients from Mumbai

DELETE FROM Orders
WHERE cno IN
(
    SELECT cno
    FROM Client
    WHERE address = 'Mumbai'
);

DELETE FROM Client
WHERE address = 'Mumbai';

//v) Count orders having amount greater than 40000

SELECT COUNT(*) AS order_count
FROM Orders
WHERE amount > 40000;

======================================================================================================================
//C)

SELECT C.*
FROM Client C
JOIN Orders O
ON C.cno = O.cno
GROUP BY C.cno, C.name, C.address
HAVING COUNT(O.orderno) =
(
    SELECT MAX(order_count)
    FROM
    (
        SELECT COUNT(orderno) AS order_count
        FROM Orders
        GROUP BY cno
    ) AS T
);

======================================================================================================================