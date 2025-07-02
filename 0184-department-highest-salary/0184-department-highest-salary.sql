# Write your MySQL query statement below


-- select d.name as Department, e.name as Employee , e.salary as Salary from employee e join department d on e.departmentId = d.id order by d.name

-- select d.name as Department, e.name as Employee , e.salary as Salary from employee e join department d on e.departmentId = d.id order by d.name


select Department.name as Department, employee.name as Employee , employee.salary as Salary from employee,Department where salary in
(select max(e.salary) from employee e where e.departmentId = department.id group by e.departmentid); 

