# Write your MySQL query statement below

select e2.name as employee from Employee e1 join Employee e2 on e2.managerId = e1.id where e1.salary < e2.salary

-- select e1.name as Employee from Employee e1 join Employee e2 on e1.managerId = e2.id where e1.salary > e2.salary;