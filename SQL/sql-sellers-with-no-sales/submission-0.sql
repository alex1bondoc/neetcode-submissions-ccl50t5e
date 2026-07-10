select seller_name 
from seller s
where 0 = (select count(*) from orders o where o.seller_id = s.seller_id and o.sale_date >= '2020-01-01' AND o.sale_date <= '2020-12-31');