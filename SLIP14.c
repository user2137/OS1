//SLIP - 14

//Q1
======================================================================================================================

#include <stdio.h>

struct Student
{
    char Stud_name[50];
    int Age;
    float Percentage;
};

int main()
{
    struct Student s[100], temp;
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter student name: ");
        scanf("%s", s[i].Stud_name);

        printf("Enter age: ");
        scanf("%d", &s[i].Age);

        printf("Enter percentage: ");
        scanf("%f", &s[i].Percentage);
    }

    for(i = 0; i < n - 1; i++)
    {
        int min = i;

        for(j = i + 1; j < n; j++)
        {
            if(s[j].Percentage < s[min].Percentage)
            {
                min = j;
            }
        }

        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }

    FILE *fp;

    fp = fopen("sortedstudent.txt", "w");

    for(i = 0; i < n; i++)
    {
        fprintf(fp, "%s %d %.2f\n",
                s[i].Stud_name,
                s[i].Age,
                s[i].Percentage);
    }

    fclose(fp);

    printf("\nStudents sorted by percentage:\n");

    for(i = 0; i < n; i++)
    {
        printf("%s %d %.2f\n",
               s[i].Stud_name,
               s[i].Age,
               s[i].Percentage);
    }

    printf("\nSorted data stored in sortedstudent.txt\n");

    return 0;
}

======================================================================================================================
//DBMS
======================================================================================================================

CREATE DATABASE doctor_patient_db;

CREATE TABLE Doctor
(
    dcode INT PRIMARY KEY,
    doctor_name VARCHAR(50),
    specialization VARCHAR(50),
    address VARCHAR(100),
    phone_no VARCHAR(15),
    fees DECIMAL(10,2)
);

CREATE TABLE Patient
(
    pcode INT PRIMARY KEY,
    Patient_name VARCHAR(50),
    symptoms VARCHAR(100),
    dcode INT,
    FOREIGN KEY(dcode) REFERENCES Doctor(dcode)
);

INSERT INTO Doctor VALUES
(101, 'Dr. Patil', 'Orthopedic', 'Shivajinagar', '9876543210', 500),
(102, 'Dr. Sharma', 'Neurologist', 'Sadashiv Peth', '9876543211', 800),
(103, 'Dr. Kulkarni', 'Orthopedic', 'Shivajinagar', '9876543212', 600),
(104, 'Dr. Deshmukh', 'Cardiologist', 'Camp', '9876543213', 700),
(105, 'Dr. Joshi', 'Neurologist', 'Sadashiv Peth', '9876543214', 900);

INSERT INTO Patient VALUES
(201, 'Mohan', 'Fever', 101),
(202, 'Meena', 'Cold', 102),
(203, 'Mahesh', 'Fever', 103),
(204, 'Rohan', 'Headache', 104),
(205, 'Priya', 'Fever', 105),
(206, 'Amit', 'Cough', 101);

//B) Queries
======================================================================================================================

//i) Display patients whose name starts with M

SELECT *
FROM Patient
WHERE Patient_name LIKE 'M%';

//ii) Count doctors having specialization Neurologist

SELECT COUNT(*) AS neurologist_count
FROM Doctor
WHERE specialization = 'Neurologist';

//iii) Display patients suffering from Fever

SELECT *
FROM Patient
WHERE symptoms = 'Fever';

//iv) Display specialization and phone number of doctors from Sadashiv Peth

SELECT specialization, phone_no
FROM Doctor
WHERE address = 'Sadashiv Peth';

//v) Change Dr. Patil address to Camp

UPDATE Doctor
SET address = 'Camp'
WHERE doctor_name = 'Dr. Patil';

======================================================================================================================
//C)

SELECT P.*
FROM Patient P
JOIN Doctor D
ON P.dcode = D.dcode
WHERE D.address = 'Shivajinagar'
AND D.specialization = 'Orthopedic';

======================================================================================================================