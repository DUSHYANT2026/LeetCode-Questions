# Write your MySQL query statement below


with temp as
(
    select player_id as id, min(event_date) as loginday from activity group by player_id 
),
newtemp as
(
    select a.player_id as id from temp t join Activity a on t.id = a.player_id where datediff(a.event_date, t.loginday) = 1
),
temp1 as
(
    select count(distinct player_id) as totalcount from Activity 
)

select if(t1.totalcount = 0 ,0 ,round(count(distinct nt.id) / t1.totalcount, 2) )as fraction from newtemp nt join temp1 t1; 