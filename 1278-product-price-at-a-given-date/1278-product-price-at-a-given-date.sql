WITH ranked_product AS (
    SELECT *,
           ROW_NUMBER() OVER (PARTITION BY product_id ORDER BY change_date DESC) AS rn
    FROM products
    WHERE change_date <= '2019-08-16'
)

SELECT 
    p.product_id,
    CASE 
        WHEN rp.new_price IS NULL THEN 10 
        ELSE rp.new_price 
    END AS price
FROM (SELECT DISTINCT product_id FROM products) p
LEFT JOIN ranked_product rp 
    ON p.product_id = rp.product_id AND rp.rn = 1;
