# Write your MySQL query statement below


select product_id, year as first_year, quantity, price from sales group by product_id having year = min(year)