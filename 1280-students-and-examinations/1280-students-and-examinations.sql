# Write your MySQL query statement below

WITH cte1 AS
(SELECT st.student_id,st.student_name,sb.subject_name
from Students as st CROSS JOIN Subjects as sb),

cte2 AS
(SELECT student_id,subject_name,COUNT(subject_name) as count
FROM Examinations
GROUP BY student_id,subject_name) 

SELECT cte1.student_id,cte1.student_name,cte1.subject_name,
    (CASE WHEN count IS NULL THEN 0 ELSE count END) as attended_exams
FROM cte1 LEFT JOIN cte2
ON cte1.student_id=cte2.student_id AND cte1.subject_name=cte2.subject_name
ORDER BY cte1.student_id,cte1.subject_name