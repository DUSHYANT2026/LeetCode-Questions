# Write your MySQL query statement below


select name from employee where id = (select managerId from employee group by managerId having count(managerId) >= 5)