# Write your MySQL query statement below



select  Department,Employee,Salary from (select  D.name as Department,E.name as Employee,E.salary as Salary ,
 DENSE_RANK() over (partition by e.departmentId ORDER BY e.salary DESC) AS newrank  
from employee e join department d on e.departmentId = d.id order by e.salary desc ) newtable where newrank < 4




