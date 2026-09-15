-- Last updated: 9/15/2026, 11:57:17 PM
# Write your MySQL query statement below
SELECT customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (
    SELECT COUNT(*) 
    FROM Product
);