# Write your MySQL query statement below

-- select Email from person where (
select email from person group by email having count(email) > 1