# Write your MySQL query statement below

select P.product_name, S.year, S.price
from Sales as S INNER JOIN Product as P
ON S.product_id=P.product_id