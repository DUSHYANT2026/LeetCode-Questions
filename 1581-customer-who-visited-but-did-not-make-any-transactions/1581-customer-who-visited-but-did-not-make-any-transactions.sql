# Write your MySQL query statement below

with temp as
(
    select transaction_id as newcheck from transactions
    union all
    select visit_id as newcheck from transactions
)

-- select distinct(newcheck) from temp
select customer_id, count(visit_id) as count_no_trans from visits 
where visit_id not in (select distinct (newcheck) from temp) group by customer_id