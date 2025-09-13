-- Write your PostgreSQL query statement below


with temp as(
select m.employee_id, e.employee_name, e.department  
from employees e join meetings m on e.employee_id = m.employee_id 
    group by m.employee_id,
             DATE_PART('week', m.meeting_date),
             DATE_PART('year', m.meeting_date),
             e.employee_name,
             e.department
    having sum(m.duration_hours) > 20
)
-- select * from temp;

select employee_id, employee_name, department, count(employee_id) as meeting_heavy_weeks
from temp  group by employee_id , employee_name , department having count(employee_id) >= 2
order by meeting_heavy_weeks desc , employee_name asc