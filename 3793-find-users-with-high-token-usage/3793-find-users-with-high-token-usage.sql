# Write your MySQL query statement below

with temp as
(
select user_id, count(user_id) as prompt_count, round(sum(tokens)/count(user_id),2) as avg_tokens, max(tokens) as x  
from prompts group by user_id
)

select user_id, prompt_count, avg_tokens from temp where prompt_count > 2 && x > avg_tokens order by avg_tokens desc , user_id