# Write your MySQL query statement below

with temp as(
select requester_id  from RequestAccepted 
union all
select accepter_id from RequestAccepted 
)

select  requester_id as id, count(requester_id) as num from temp group by requester_id order by num desc limit 1;