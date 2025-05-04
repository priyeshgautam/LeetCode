

SELECT 
  e.reports_to AS employee_id,
  m.name,
  COUNT(*) AS reports_count,
  ROUND(AVG(e.age), 0) AS average_age
FROM employees e
JOIN employees m ON e.reports_to = m.employee_id
WHERE e.reports_to IS NOT NULL
GROUP BY e.reports_to, m.name
order by e.reports_to;
