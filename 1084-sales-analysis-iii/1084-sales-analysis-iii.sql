# Write your MySQL query statement below



with temp as(
select s.product_id, product_name from product p left join sales s on p.product_id = s.product_id  
where year(sale_date) = '2019' && (month(sale_date) = '1' or month(sale_date) = '2' or month(sale_date) = '3')
)

select * from temp where product_id not in (select product_id from sales where sale_date > '2019-03-31' or sale_date < '2019-01-01');

