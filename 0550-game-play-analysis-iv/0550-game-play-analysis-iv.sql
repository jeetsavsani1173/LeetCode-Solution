# Write your MySQL query statement below
with T1 as
(select player_id,min(event_date) as event_start_date 
from Activity
group by player_id)

select ROUND(COUNT(distinct T1.player_id)/
(select COUNT(distinct player_id) from Activity),2) AS fraction

from T1 join Activity A
ON T1.player_id=A.player_id and datediff(T1.event_start_date,A.event_date)=-1