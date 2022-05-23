# Write your MySQL query statement below
SELECT name as Customers
FROM Customers
Where id NOT IN (
SELECT customerId 
FROM Orders);