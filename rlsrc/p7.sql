/*
Question:
---------
Find the company that has the lowest total employee count.

Input Table: CompanyDetails

+---------+----------+----------+
| Company | Position | Employee |
+---------+----------+----------+
| ABC     | blah     | 20       |
| ABC     | blah     | 15       |
| ABC     | blah     | 5        |
| XYZ     | blah     | 10       |
| XYZ     | blah     | 12       |
| XYZ     | blah     | 5        |
| MNO     | blah     | 20       |
| MNO     | blah     | 5        |
+---------+----------+----------+

Expected Output:
----------------

+---------+----------------+
| Company | TotalEmployees |
+---------+----------------+
| MNO     | 25             |
+---------+----------------+

Explanation:
------------
ABC = 20 + 15 + 5 = 40
XYZ = 10 + 12 + 5 = 27
MNO = 20 + 5 = 25

MNO has the lowest total employee count.
*/

SELECT
    Company,
    SUM(Employee) AS TotalEmployees
FROM CompanyDetails
GROUP BY Company
LIMIT 1; --give lowest value