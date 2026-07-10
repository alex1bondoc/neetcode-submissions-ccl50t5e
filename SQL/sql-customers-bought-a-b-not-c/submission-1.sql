-- Write your query below
select customer_id, customer_name 
from customers c
where 0 = (select count(*) from orders o where o.customer_id = c.customer_id and o.product_name = 'C')
and 0 < (select count(*) from orders o where o.customer_id = c.customer_id and o.product_name = 'B')
and 0 < (select count(*) from orders o where o.customer_id = c.customer_id and o.product_name = 'A');