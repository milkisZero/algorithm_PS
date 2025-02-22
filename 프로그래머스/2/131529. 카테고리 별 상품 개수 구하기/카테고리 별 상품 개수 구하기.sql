-- 코드를 입력하세요
SELECT LEFT(PRODUCT_CODE, 2) AS CATEGORY,	count(*) as PRODUCTS
from PRODUCT 
group by CATEGORY
order by CATEGORY asc
