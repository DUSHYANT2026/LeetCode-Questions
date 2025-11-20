# Write your MySQL query statement below
with temp as (
select *,
count(order_id) as total_orders, 
round((sum(order_rating)/ (sum(if(order_rating != 'NULL', 1, 0 )) )),2) as average_rating ,   
sum(if(order_rating != 'NULL', 1, 0 )) as z, 
round((sum(case when hour(order_timestamp) BETWEEN 11 AND 13 or hour(order_timestamp) BETWEEN 18 AND 20 then 1 else 0 end)  / count(order_id) ) * 100 , 0)  as peak_hour_percentage
from restaurant_orders group by customer_id
)

select customer_id,  total_orders, peak_hour_percentage, average_rating 
from temp where  total_orders >= 3 && average_rating >= 4.00 &&   peak_hour_percentage >= 60 && (z/total_orders)*100 >= 50  order by average_rating desc , customer_id desc;