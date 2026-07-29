-- Last updated: 7/29/2026, 11:40:39 AM
# Write your MySQL query statement below
SELECT DISTINCT s1.id, s1.visit_date, s1.people
FROM Stadium s1, Stadium s2, Stadium s3
WHERE s1.people >= 100 
  AND s2.people >= 100 
  AND s3.people >= 100
  AND (
      -- s1 is the 1st of 3 consecutive ids
      (s1.id + 1 = s2.id AND s1.id + 2 = s3.id) 
      OR 
      -- s1 is the 2nd of 3 consecutive ids
      (s1.id - 1 = s2.id AND s1.id + 1 = s3.id) 
      OR 
      -- s1 is the 3rd of 3 consecutive ids
      (s1.id - 2 = s2.id AND s1.id - 1 = s3.id)
  )
ORDER BY s1.visit_date ASC;