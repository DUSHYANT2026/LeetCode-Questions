# Write your MySQL query statement below

with temp as
(
select product_name , year(order_date) as years, month(order_date) as months, sum(unit) as unit  
from products p join orders o on p.product_id = o.product_id group by product_name , months , years
)

select product_name, unit from temp where unit >= 100 && years = 2020 && months = 2