-- Last updated: 7/29/2026, 11:40:30 AM
# Write your MySQL query statement below
SELECT customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (
    SELECT COUNT(*) 
    FROM Product
);