# Write your MySQL query statement below

with temp as
(
select e.employee_id as employee_id, name, review_date, rating , row_number() over (partition by employee_id order by review_date desc) as rownum   
from employees e join performance_reviews p on e.employee_id = p.employee_id
),
temp2 as
(
select employee_id, name, review_date, rating, rownum,  count(employee_id) as countid,
sum(if(rownum = 1, rating , 0)) as firstr , sum(if(rownum = 2, rating , 0)) as secondr , sum(if(rownum = 3, rating , 0)) as thirdr  from temp group by employee_id 
)

select employee_id, name, (firstr - thirdr) as improvement_score from temp2 where firstr > secondr && secondr > thirdr && countid > 2 order by (firstr - thirdr) desc , name