-- Last updated: 9/15/2026, 11:56:02 PM
# Write your MySQL query statement below
SELECT 
    eu.unique_id,
    e.name
FROM 
    Employees e
LEFT JOIN 
    EmployeeUNI eu ON e.id = eu.id;