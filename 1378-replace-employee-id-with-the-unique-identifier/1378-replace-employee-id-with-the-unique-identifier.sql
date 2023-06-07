# Write your MySQL query statement below

select E2.unique_id,E1.name
from Employees as E1 LEFT JOIN EmployeeUNI as E2
ON E1.id=E2.id 