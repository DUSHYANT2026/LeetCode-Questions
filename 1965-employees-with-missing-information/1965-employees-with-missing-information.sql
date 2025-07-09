# Write your MySQL query statement below
with temp as( select employee_id from employees union all select employee_id from salaries)

select employee_id from temp where employee_id not in (select e.employee_id from employees e join salaries s on e.employee_id = s.employee_id) order by employee_id