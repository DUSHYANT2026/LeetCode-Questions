# Write your MySQL query statement below

with temp as
(
    select distinct visited_on, SUM(amount) over(order by visited_on range between interval 6 day PRECEDING and CURRENT row) as amount 
    from Customer limit 10000 OFFSET 6
)
select visited_on, amount , round(amount/7, 2) as average_amount from temp;