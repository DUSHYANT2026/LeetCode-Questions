# Write your MySQL query statement below


with temp1 as ( 
    select 'High Salary' as category, count(income) as accounts_count from accounts where income > 50000 union 
    select 'Low Salary' as category, count(income) as accounts_count from accounts where income < 20000 union 
    select 'Average Salary' as category, count(income) as accounts_count from accounts where income <= 50000 and income >= 20000
)
select * from temp1;
