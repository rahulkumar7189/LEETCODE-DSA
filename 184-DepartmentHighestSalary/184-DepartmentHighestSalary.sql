-- Last updated: 7/29/2026, 11:40:49 AM
# Write your MySQL query statement below
SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM Employee e
JOIN Department d 
    ON e.departmentId = d.id
WHERE (e.departmentId, e.salary) IN (
    SELECT 
        departmentId, 
        MAX(salary)
    FROM Employee
    GROUP BY departmentId
);