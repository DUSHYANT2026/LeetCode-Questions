# Write your MySQL query statement below
select lastName, FirstName, city, state from person p left join address a on p.personId = a.personId 