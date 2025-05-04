WITH RunningTotal AS (
    SELECT 
        person_id,
        person_name,
        weight,
        SUM(weight) OVER (ORDER BY turn) AS total_weight
    FROM Queue
    order by turn
)


SELECT person_name
FROM RunningTotal
WHERE total_weight <= 1000
order by total_weight desc
LIMIT 1;