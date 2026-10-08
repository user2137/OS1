//SLIP - 15

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

    for(i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = temp;
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

CREATE DATABASE game_player_db;

CREATE TABLE Game
(
    gname VARCHAR(50) PRIMARY KEY,
    noofplayers INT,
    coachname VARCHAR(50),
    captain_name VARCHAR(50)
);

CREATE TABLE Player
(
    pno INT PRIMARY KEY,
    pname VARCHAR(50),
    gname VARCHAR(50),
    FOREIGN KEY(gname) REFERENCES Game(gname)
);

INSERT INTO Game VALUES
('Hockey', 11, 'Dhoni', 'RAHUL'),
('Cricket', 11, 'Dhoni', 'ROHIT'),
('Football', 11, 'Tendulkar', 'AMIT'),
('Kho Kho', 9, 'Sharma', 'SURESH'),
('Kabaddi', 7, 'Patil', 'RAJ');

INSERT INTO Player VALUES
(101, 'Rahul', 'Hockey'),
(102, 'Amit', 'Hockey'),
(103, 'Rohan', 'Cricket'),
(104, 'Sahil', 'Cricket'),
(105, 'Priya', 'Football'),
(106, 'Neha', 'Football'),
(107, 'Vikas', 'Kho Kho'),
(108, 'Akash', 'Kabaddi');

//B) Queries
======================================================================================================================

//i) Display players playing Hockey

SELECT P.*
FROM Player P
JOIN Game G
ON P.gname = G.gname
WHERE G.gname = 'Hockey';

//ii) Find average number of players

SELECT AVG(noofplayers) AS average_players
FROM Game;

//iii) Delete players playing Kho Kho

DELETE FROM Player
WHERE gname = 'Kho Kho';

//iv) Display players not playing Cricket

SELECT *
FROM Player
WHERE gname <> 'Cricket';

//v) Update coach Dhoni to Tendulkar for Cricket

UPDATE Game
SET coachname = 'Tendulkar'
WHERE gname = 'Cricket'
AND coachname = 'Dhoni';

======================================================================================================================
//C)

SELECT *
FROM Game
WHERE noofplayers =
(
    SELECT MAX(noofplayers)
    FROM Game
);

======================================================================================================================