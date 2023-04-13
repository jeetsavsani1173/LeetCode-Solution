# Write your MySQL query statement below

select product_id, 'store1' As 'store' , store1 As price
from Products 
where store1 is not null
union
select product_id, 'store2' As 'store' , store2 As price
from Products 
where store2 is not null
union
select product_id, 'store3' As 'store' , store3 As price
from Products 
where store3 is not null