# Write your MySQL query statement below

select s1.score , (select count(distinct score) from Scores As s2 where s2.score>=s1.score) As "Rank"
from Scores As s1
Order by s1.score DESC
