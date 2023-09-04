# Write your MySQL query statement below

SELECT w.ID FROM WEATHER w JOIN WEATHER e ON DATEDIFF(w.recordDate,e.recordDate)=1 AND w.temperature>e.temperature;