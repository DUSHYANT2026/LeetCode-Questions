# Write your MySQL query statement below

with temp as (
    select person_id, person_name, weight, turn , sum(weight) over (order by turn) as new_weight from Queue 
)
select person_name from temp where new_weight <= 1000 order by new_weight desc limit 1