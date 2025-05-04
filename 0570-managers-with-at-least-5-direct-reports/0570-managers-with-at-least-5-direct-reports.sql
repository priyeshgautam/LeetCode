# Write your MySQL query statement below

select name from employee e inner join (
select managerId from employee 
group by managerId
having count(1) >= 5
) temp on e.id = temp.managerId