# Write your MySQL query statement below

select A1.machine_id,ROUND(AVG(A2.timestamp-A1.timestamp),3) AS processing_time
from Activity as A1,Activity as A2
where A1.machine_id=A2.machine_id and A1.process_id=A2.process_id 
and A1.activity_type='start' and A2.activity_type='end'
GROUP BY A1.machine_id