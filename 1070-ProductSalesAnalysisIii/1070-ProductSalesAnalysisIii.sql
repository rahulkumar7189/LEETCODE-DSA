-- Last updated: 9/15/2026, 11:57:13 PM
# Write your MySQL query statement below
SELECT 
    product_id, 
    year AS first_year, 
    quantity, 
    price
FROM Sales
WHERE (product_id, year) IN (
    SELECT 
        product_id, 
        MIN(year)
    FROM Sales
    GROUP BY product_id
);