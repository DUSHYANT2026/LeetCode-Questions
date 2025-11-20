# Write your MySQL query statement below

with temp as (
select * , sum(if(event_type = 'scroll' , 1 , 0)) as scroll_count, 
sum(if(event_type = 'click' , 1 , 0)) as click_count,
sum(if(event_type = 'purchase' , 1 , 0)) as purchase_count,
max(event_timestamp) as max_time,
min(event_timestamp) as min_time
from app_events group by user_id
)


select session_id, user_id , TIMESTAMPDIFF(MINUTE,min_time,max_time) as session_duration_minutes, scroll_count 
from temp where TIMESTAMPDIFF(MINUTE,min_time,max_time) > 30 && scroll_count >= 5 &&
(click_count/scroll_count) < 0.20 && purchase_count = 0 order by scroll_count desc , session_id