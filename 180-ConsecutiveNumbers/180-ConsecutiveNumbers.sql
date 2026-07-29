-- Last updated: 7/29/2026, 11:40:51 AM
# Write your MySQL query statement below
WITH RankedLogs AS (
    SELECT 
        num,
        LEAD(num, 1) OVER (ORDER BY id) AS next_num,
        LEAD(num, 2) OVER (ORDER BY id) AS next_next_num
    FROM Logs
)
SELECT DISTINCT num AS ConsecutiveNums
FROM RankedLogs
WHERE num = next_num AND num = next_next_num;