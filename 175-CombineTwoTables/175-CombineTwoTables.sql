-- Last updated: 7/5/2026, 11:04:19 PM
# Write your MySQL query statement below
SELECT p.firstName, p.lastName, a.city, a.state
FROM Person p
LEFT JOIN Address a USING (personId);