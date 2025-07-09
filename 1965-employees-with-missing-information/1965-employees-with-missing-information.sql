# Write your MySQL query statement below
-- with temp as( select employee_id from employees union all select employee_id from salaries)

-- select employee_id from temp where employee_id not in (select e.employee_id from employees e join salaries s on e.employee_id = s.employee_id) order by employee_id


(SELECT E.employee_id
FROM Employees E
LEFT JOIN Salaries S on E.employee_id = S.employee_id
WHERE S.salary IS NULL

UNION

SELECT S.employee_id
FROM Employees E
RIGHT JOIN Salaries S on E.employee_id = S.employee_id
WHERE E.name IS NULL)
ORDER BY employee_id