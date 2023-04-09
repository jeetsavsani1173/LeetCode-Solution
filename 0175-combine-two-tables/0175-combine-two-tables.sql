# Write your MySQL query statement below

select firstName, LastName, city, state 
from Address RIGHT JOIN Person
ON Person.personId=Address.personId;
