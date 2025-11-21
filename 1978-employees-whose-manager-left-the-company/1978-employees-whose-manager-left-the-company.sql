# Write your MySQL query statement below

-- with temp as
-- (select  employee_id from Employees)

select employee_id from Employees where salary < 30000 && manager_id not in (select  employee_id from Employees) order by employee_id
