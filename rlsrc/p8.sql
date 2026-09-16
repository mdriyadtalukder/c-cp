/*
Question:
Find the maximum salary for each department.

Tables:

employee

+-------+--------+---------------+
| name  | salary | department_id |
+-------+--------+---------------+
| John  | 50000  | 1             |
| Alice | 70000  | 1             |
| Bob   | 60000  | 2             |
| Carol | 80000  | 2             |
| David | 55000  | 3             |
+-------+--------+---------------+

department

+----+-----------------+
| id | department_name |
+----+-----------------+
| 1  | HR              |
| 2  | IT              |
| 3  | Sales           |
+----+-----------------+

Output:

+-----------------+------------+
| department_name | MaxSalary  |
+-----------------+------------+
| HR              | 70000      |
| IT              | 80000      |
| Sales           | 55000      |
+-----------------+------------+
*/

SELECT
    d.department_name,
    MAX(e.salary) AS MaxSalary
FROM employee e
JOIN department d
ON e.department_id = d.id
GROUP BY d.department_name;