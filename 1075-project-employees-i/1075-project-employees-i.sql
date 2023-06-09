# Write your MySQL query statement below

select p.project_id,ROUND(AVG(e.experience_years),2) AS average_years
from Project as p inner join Employee as e
ON p.employee_id=e.employee_id
GROUP by p.project_id