# Write your MySQL query statement below

with temp as (
select max(event_id) as id , sum(if(event_type = 'downgrade', 1, 0)) as x , max( monthly_amount) as max_historical_amount,
if(event_type != 'cancel', max(event_date), 0) as max_date,
if(event_type != 'cancel', min(event_date), 0) as min_date
from subscription_events group by user_id 
)

select  user_id, plan_name as current_plan ,monthly_amount as current_monthly_amount, max_historical_amount, 
DATEDIFF(max_date,min_date) AS days_as_subscriber 
from subscription_events join temp where event_id = id && DATEDIFF(max_date,min_date) >= 60 && plan_name  != 'NULL' &&
monthly_amount <  max_historical_amount/2 && x >= 1  order by days_as_subscriber desc , user_id

