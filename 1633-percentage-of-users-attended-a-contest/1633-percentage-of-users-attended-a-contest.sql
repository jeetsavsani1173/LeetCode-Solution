# Write your MySQL query statement below

select r.contest_id, ROUND(100*COUNT(*)/(select COUNT(user_id) from Users),2) AS percentage
from Users as u INNER JOIN Register as r
ON u.user_id=r.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC,r.contest_id ASC