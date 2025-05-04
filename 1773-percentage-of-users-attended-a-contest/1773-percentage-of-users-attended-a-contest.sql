# Write your MySQL query statement below
select 
r.contest_id, 
round((count(1)/(select count(1) from users)*100),2) percentage 
from register r join users u on u.user_id = r.user_id
group by r.contest_id order by percentage desc, contest_id asc