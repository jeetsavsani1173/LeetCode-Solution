# Write your MySQL query statement below

select firstName, LastName, city, state 
from Person LEFT JOIN Address
ON Person.personId=Address.personId;
