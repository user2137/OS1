//SLIP - 5  
  
//Q1  
======================================================================================================================  
#include <stdio.h>  
#include <stdlib.h>  
 
struct Node  
{  
    int data;  
    struct Node *next;  
};  
 
struct Node *head = NULL;  
 
void create(int n)  
{  
    struct Node *newNode;  
    struct Node *temp;  
    int i, value;  
 
    for(i = 0; i < n; i++)  
    {  
        newNode = (struct Node *)malloc(sizeof(struct Node));  
 
        printf("Enter element: ");  
        scanf("%d", &value);  
 
        newNode->data = value;  
        newNode->next = NULL;  
 
        if(head == NULL)  
        {  
            head = newNode;  
        }  
        else  
        {  
            temp = head;  
 
            while(temp->next != NULL)  
            {  
                temp = temp->next;  
            }  
 
            temp->next = newNode;  
        }  
    }  
}  
 
void display()  
{  
    struct Node *temp;  
 
    temp = head;  
 
    printf("Linked List:\n");  
 
    while(temp != NULL)  
    {  
        printf("%d -> ", temp->data);  
        temp = temp->next;  
    }  
 
    printf("NULL\n");  
}  
 
int main()  
{  
    int n;  
 
    printf("Enter number of nodes: ");  
    scanf("%d", &n);  
 
    create(n);  
    display();  
 
    return 0;  
}  
======================================================================================================================  
//DBMS  
======================================================================================================================  
 
CREATE DATABASE doctor_patient_db;  
 
CREATE TABLE Doctor  
(  
    dno INT PRIMARY KEY,  
    dname VARCHAR(50),  
    city VARCHAR(50)  
);  
 
CREATE TABLE Patient  
(  
    pno INT PRIMARY KEY,  
    pat_name VARCHAR(50),  
    city VARCHAR(50),  
    disease VARCHAR(50)  
);  
 
CREATE TABLE Doctor_Patient  
(  
    dno INT,  
    pno INT,  
    fees DECIMAL(10,2),  
    PRIMARY KEY(dno, pno),  
    FOREIGN KEY(dno) REFERENCES Doctor(dno),  
    FOREIGN KEY(pno) REFERENCES Patient(pno)  
);  
 
INSERT INTO Doctor VALUES  
(1, 'Dr. Kumar', 'Pune'),  
(2, 'Dr. Patil', 'Nagpur'),  
(3, 'Dr. Sharma', 'Mumbai'),  
(4, 'Dr. Joshi', 'Nagpur'),  
(5, 'Dr. Kulkarni', 'Nashik');  
 
INSERT INTO Patient VALUES  
(101, 'Amit', 'Pune', 'Asthama'),  
(102, 'Anjali', 'Mumbai', 'Cancer'),  
(103, 'Rahul', 'Nashik', 'Fever'),  
(104, 'Akash', 'Pune', 'Asthama'),  
(105, 'Sneha', 'Nagpur', 'Cancer'),  
(106, 'Riya', 'Nashik', 'Fever');  
 
INSERT INTO Doctor_Patient VALUES  
(1, 101, 200),  
(1, 102, 300),  
(2, 103, 250),  
(2, 104, 200),  
(3, 105, 500),  
(4, 106, 300),  
(1, 104, 350);  
 
//B) Queries  
======================================================================================================================  
 
//i) List details of all doctors from Nagpur city  
 
SELECT *  
FROM Doctor  
WHERE city = 'Nagpur';  
 
//ii) Display count of patients  
 
SELECT COUNT(*) AS patient_count  
FROM Patient;  
 
//iii) List names of patients suffering from cancer  
 
SELECT pat_name  
FROM Patient  
WHERE disease = 'cancer';  
 
//iv) Change city of Dr. Patil to Pune  
 
UPDATE Doctor  
SET city = 'Pune'  
WHERE dname = 'Dr. Patil';  
 
//v) List names of patients starting with alphabet A  
 
SELECT pat_name  
FROM Patient  
WHERE pat_name LIKE 'A%';  
======================================================================================================================  
//C)  
 
SELECT COUNT(*) AS patient_count  
FROM Doctor_Patient DP  
JOIN Doctor D  
ON DP.dno = D.dno  
JOIN Patient P  
ON DP.pno = P.pno  
WHERE P.disease = 'Asthama'  
AND DP.fees = 200  
AND D.dname = 'Dr. Kumar';  
======================================================================================================================  