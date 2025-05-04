# Write your MySQL query statement below
with occurence as (
    select *, count(*) as c
    from employee
    group by employee_id
)

select e.employee_id, e.department_id
from  employee e join  occurence o 
on e.employee_id = o.employee_id 
where c = 1 or e.primary_flag = 'Y'