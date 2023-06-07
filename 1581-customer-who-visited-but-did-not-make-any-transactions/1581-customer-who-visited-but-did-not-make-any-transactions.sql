# Write your MySQL query statement below

select V.customer_id,COUNT(V.visit_id) As count_no_trans
from Visits as V LEFT JOIN Transactions as T
ON V.visit_id=T.visit_id
where T.transaction_id is null
GROUP BY V.customer_id