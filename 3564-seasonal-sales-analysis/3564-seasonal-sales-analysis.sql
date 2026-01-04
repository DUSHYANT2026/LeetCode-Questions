# Write your MySQL query statement below

with temp as
(
select p.product_id as product_id, category ,quantity, price, 
if(month(sale_date) = 12 or month(sale_date) = 1 or month(sale_date) = 2 , 'Winter', if(month(sale_date) = 3 or month(sale_date) = 4 or  month(sale_date) = 5 , 'Spring', 
if(month(sale_date) = 6 or month(sale_date) = 7 or month(sale_date) = 8, 'Summer' , 'Fall')))  as season
from sales s join products p on s.product_id = p.product_id
),
temp2 as
(
select season, category, sum(quantity) as total_quantity , round(sum(price* quantity),2) 
as total_revenue from temp group by season, category order by season , sum(quantity) desc, round(sum(price* quantity),2) desc 
)

select * from temp2 group by season