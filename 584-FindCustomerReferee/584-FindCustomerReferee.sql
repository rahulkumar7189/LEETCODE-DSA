-- Last updated: 7/5/2026, 11:04:09 PM
# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE referee_id != 2 OR referee_id IS NULL;