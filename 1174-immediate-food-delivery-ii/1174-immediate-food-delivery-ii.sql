# Write your MySQL query statement below

# common table expression
with cte AS
(select * ,RANK() OVER(PARTITION BY customer_id ORDER BY order_date) AS order_number, 
(CASE WHEN datediff(order_date,customer_pref_delivery_date)=0 THEN "immediate" ELSE "scheduled" END) AS order_type
from Delivery)

select ROUND(100*SUM(order_type="immediate")/COUNT(*),2) AS immediate_percentage
from cte 
where order_number=1