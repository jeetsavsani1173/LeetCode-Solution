# Write your MySQL query statement below

select id,"Root" As 'type' 
from Tree
where p_id is null
Union
select id,"Inner" As 'type'
from Tree 
where id In (select p_id from Tree) and p_id is not null
Union
select id,"Leaf" As 'type'
from Tree 
where id not In (select distinct p_id from Tree where p_id is not null) and p_id is not null