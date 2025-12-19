# Write your MySQL query statement below

select lastName, FirstName, city, state from person p  left join address a on p.personId = a.personId 



-- with temp as(

-- select personId from person
-- union all
-- select personId from address
-- )
-- select distinct(personId) from temp order by personId desc
