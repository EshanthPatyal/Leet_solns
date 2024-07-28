# Write your MySQL query statement below
Select d.name as Department,e.name as Employee,e.salary as Salary 
from Employee as e, Department as d
where e.departmentId = d.id AND (e.departmentID,salary) IN (
    select departmentId,MAX(salary)
    from Employee
    group by departmentId
)