# Write your MySQL query statement below
select customer_number
from (select customer_number, DENSE_RANK() over (order by count desc) as 'ranking'
      from (select customer_number, count(customer_number) as count from orders group by customer_number)sub1
      ) sub2  
where sub2.ranking = 1