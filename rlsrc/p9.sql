/*
Question:
Select the Top 10 employees based on salary.

Input:

Employee

+----+----------+--------+
| ID | Name     | Salary |
+----+----------+--------+
| 1  | John     | 90000  |
| 2  | Alice    | 75000  |
| 3  | Bob      | 60000  |
| 4  | Carol    | 95000  |
| 5  | David    | 50000  |
| 6  | Eva      | 88000  |
| 7  | Frank    | 72000  |
| 8  | Grace    | 65000  |
| 9  | Henry    | 98000  |
|10  | Ivy      | 55000  |
|11  | Jack     | 91000  |
|12  | Kim      | 70000  |
+----+----------+--------+

Output:

+----------+--------+
| Name     | Salary |
+----------+--------+
| Henry    | 98000  |
| Carol    | 95000  |
| Jack     | 91000  |
| John     | 90000  |
| Eva      | 88000  |
| Alice    | 75000  |
| Frank    | 72000  |
| Kim      | 70000  |
| Grace    | 65000  |
| Bob      | 60000  |
+----------+--------+
*/
SELECT TOP 10 Name, Salary
FROM Employee
ORDER BY Salary DESC;