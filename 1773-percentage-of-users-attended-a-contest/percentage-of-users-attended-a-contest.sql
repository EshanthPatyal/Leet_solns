# Write your MySQL query statement below
Select contest_id,Round(count(user_id)*100/(select count(user_id) from Users),2) as percentage
from Register
group by contest_id
order by percentage desc,contest_id