# Write your MySQL query statement below

select e1.name
FROM Employee as e1 JOIN Employee as e2
ON e1.id=e2.managerId
GROUP BY e2.managerId
HAVING COUNT(*)>=5
