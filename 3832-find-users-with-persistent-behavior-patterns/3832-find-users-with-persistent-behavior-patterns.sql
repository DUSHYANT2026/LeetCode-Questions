# Write your MySQL query statement below
with temp as (
select user_id, action_date, action, rank() over (partition by user_id, action order by action_date asc) as nrank,
lag(action_date) over (partition by user_id, action order by action_date asc) as newrank from activity 
),
temp2 as 
(
select * from temp where datediff(action_date, newrank) = 1 or nrank = 1
),
temp3 as (
select user_id, action, count(action) as streak_length, min(action_date) as start_date, max(action_date) as end_date from temp2 group by user_id, action
)

select * from temp3 where streak_length >= 5 order by streak_length desc, user_id 
