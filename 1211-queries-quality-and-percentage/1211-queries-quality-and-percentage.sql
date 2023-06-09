# Write your MySQL query statement below

select q2.query_name, ROUND(SUM(q2.rating/q2.position)/COUNT(*),2) AS quality ,
ROUND((select COUNT(q1.query_name) from Queries as q1 where q1.rating<3 and q1.query_name=q2.query_name)/COUNT(*)*100,2) AS poor_query_percentage
from Queries as q2
GROUP BY q2.query_name