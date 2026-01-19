# Write your MySQL query statement below

with temp as 
(
    select *, SUM(count(reaction)) OVER (PARTITION BY user_id) AS total_count,
    rank() over (partition by user_id order by count(reaction) desc) as rnk,
    count(reaction) as max_count from reactions group by user_id, reaction 
),
temp2 as
(
    select user_id, rnk, total_count, max(max_count) as new_max, reaction as dominant_reaction from temp group by user_id 
)

-- select  * from temp2
select user_id, dominant_reaction, round(new_max/total_count,2) as reaction_ratio 
from temp2 where rnk = 1 and round(new_max/total_count,2)*100 >= 60  and total_count >= 5 order by round(new_max/total_count,2) desc, user_id

