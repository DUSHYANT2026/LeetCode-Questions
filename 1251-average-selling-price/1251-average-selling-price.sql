# Write your MySQL query statement below

with temp as
(
select p.product_id  ,COALESCE(ROUND(SUM(p.price*u.units)/SUM(u.units),2),0) AS average_price from prices p JOIN UnitsSold u 
on p.product_id = u.product_id && (purchase_date between start_date and end_date)  group by p.product_id order by p.product_id
)

select product_id, average_price from temp;