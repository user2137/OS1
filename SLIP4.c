//SLIP - 4 
 
//Q1 
====================================================================================================================== 
#include <stdio.h> 
#include <stdlib.h> 
 
struct Student 
{ 
    char name[50]; 
    char className[10]; 
}; 
 
int main() 
{ 
    FILE *fp; 
    struct Student s; 
    char searchName[50]; 
    int found = 0; 
 
    fp = fopen("student.txt", "r"); 
 
    if(fp == NULL) 
    { 
        printf("File cannot be opened\n"); 
        return 0; 
    } 
 
    printf("Enter student name to search: "); 
    scanf("%s", searchName); 
 
    while(fscanf(fp, "%s %s", s.name, s.className) != EOF) 
    { 
        if(strcmp(s.name, searchName) == 0) 
        { 
            printf("Student Name: %s\n", s.name); 
            printf("Class: %s\n", s.className); 
            found = 1; 
            break; 
        } 
    } 
 
    if(found == 0) 
    { 
        printf("Student not in the list\n"); 
    } 
 
    fclose(fp); 
 
    return 0; 
} 
====================================================================================================================== 
//DBMS 
====================================================================================================================== 

CREATE DATABASE policy_customer_db; 

CREATE TABLE Customer 
( 
    cno INT PRIMARY KEY, 
    cname VARCHAR(50), 
    city VARCHAR(50), 
    agent_name VARCHAR(50) 
); 

CREATE TABLE Policy 
( 
    pno INT PRIMARY KEY, 
    pname VARCHAR(50), 
    premium_amt DECIMAL(10,2), 
    policy_type VARCHAR(20) 
        CHECK(policy_type IN ('Yearly', 'Half-yearly', 'Monthly')), 
    cno INT, 
    FOREIGN KEY(cno) REFERENCES Customer(cno) 
); 

INSERT INTO Customer VALUES 
(101, 'Rahul', 'Nashik', 'Amit'), 
(102, 'Sneha', 'Pune', 'Rohit'), 
(103, 'Amit', 'Mumbai', 'Suresh'), 
(104, 'Priya', 'Nashik', 'Amit'), 
(105, 'Rohan', 'Pune', 'Kiran'); 

INSERT INTO Policy VALUES 
(1, 'Jeevan Anand', 25000, 'Yearly', 101), 
(2, 'Jeevan Anand', 18000, 'Monthly', 102), 
(3, 'Life Plus', 30000, 'Half-yearly', 103), 
(4, 'Jeevan Anand', 22000, 'Monthly', 104), 
(5, 'Health Secure', 15000, 'Yearly', 105), 
(6, 'Life Plus', 35000, 'Yearly', 101), 
(7, 'Jeevan Anand', 20000, 'Half-yearly', 101); 

//B) Queries 
====================================================================================================================== 

//i) List details of all customers who live in city 

SELECT * 
FROM Customer 
WHERE city = 'Nashik'; 

//ii) Display average premium amount 

SELECT AVG(premium_amt) AS average_premium 
FROM Policy; 

//iii) Count customers who have taken Jeevan Anand policy 

SELECT COUNT(DISTINCT cno) AS customer_count 
FROM Policy 
WHERE pname = 'Jeevan Anand'; 

//iv) Increase premium amount for Monthly policies by 10% 

UPDATE Policy 
SET premium_amt = premium_amt * 1.10 
WHERE policy_type = 'Monthly'; 

//v) Display policy_type wise count of policies 

SELECT policy_type, COUNT(*) AS policy_count 
FROM Policy 
GROUP BY policy_type; 
====================================================================================================================== 
//C) 

SELECT policy_type, AVG(premium_amt) AS average_premium 
FROM Policy 
GROUP BY policy_type 
ORDER BY average_premium DESC 
LIMIT 1; 