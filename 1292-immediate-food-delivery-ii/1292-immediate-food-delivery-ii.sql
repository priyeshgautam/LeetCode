WITH ranked_orders AS (
    SELECT *,
           ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date) AS rn
    FROM delivery
)

SELECT 
  ROUND(
    (SUM(CASE WHEN order_date = customer_pref_delivery_date THEN 1 ELSE 0 END) / COUNT(1) *100),
    2
  ) AS immediate_percentage
FROM ranked_orders
WHERE rn = 1;
