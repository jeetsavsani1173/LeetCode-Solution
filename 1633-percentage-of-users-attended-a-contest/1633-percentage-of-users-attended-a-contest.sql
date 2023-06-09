# Write your MySQL query statement below

select contest_id,ROUND(100*COUNT(*)/(select COUNT(user_id) from Users),2)  AS percentage
from Register 
GROUP BY contest_id
ORDER BY percentage DESC,contest_id ASC