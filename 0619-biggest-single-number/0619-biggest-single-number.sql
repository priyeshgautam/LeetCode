# Write your MySQL query statement below

with ranked_t as (
    select *,
    row_number() over (partition by num order by num desc) as rn
    from mynumbers
),
dup as (select * from ranked_t where rn =2)

select max(mynumbers.num) as num from mynumbers left join dup on dup.num = mynumbers.num where dup.num is null