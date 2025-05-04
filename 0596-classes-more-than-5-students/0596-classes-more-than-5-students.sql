# Write your MySQL query statement below
with rcourses as (select class, count(*) c from courses group by class)

select class from rcourses where c>=5