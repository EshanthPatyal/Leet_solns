# Write your MySQL query statement below
select customer_id,COUNT(visit_id) as count_no_trans
from Visits
where visit_id not in (select Visits.visit_id 
from Visits inner join Transactions on Visits.visit_id=Transactions.visit_id)
group by customer_id