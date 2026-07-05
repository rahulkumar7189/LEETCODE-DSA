-- Last updated: 7/5/2026, 11:04:13 PM
# Write your MySQL query statement below
WITH RankedSalaries AS (
    SELECT 
        e.id AS employee_id,
        e.name AS employee_name,
        e.salary,
        d.name AS department_name,
        DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS salary_rank
    FROM 
        Employee e
    JOIN 
        Department d ON e.departmentId = d.id
)

SELECT 
    department_name AS Department,
    employee_name AS Employee,
    salary AS Salary
FROM 
    RankedSalaries
WHERE 
    salary_rank <= 3
ORDER BY 
    department_name, salary DESC;