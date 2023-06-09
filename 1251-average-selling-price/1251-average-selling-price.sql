# Write your MySQL query statement below

select p.product_id , ROUND(SUM(p.price*u.units)/SUM(u.units),2) AS average_price
from Prices as p inner join UnitsSold as u
ON p.product_id=u.product_id and u.purchase_date>=p.start_date and u.purchase_date<=p.end_date
GROUP by p.product_id