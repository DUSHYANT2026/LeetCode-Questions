# Write your MySQL query statement below


-- with temp as (
--     select  count(distinct(process_id)) as id from activity
-- )
-- select * from temp;

with temp1 as (
    select machine_id, count(distinct(process_id)) as id, sum(timestamp) as time, ROW_NUMBER() OVER(ORDER BY machine_id ASC) AS RowNum from activity group by machine_id , activity_type
)
select machine_id , abs(round((sum(if(Rownum%2 = 0, time , -time ))) / id ,3)) as processing_time from temp1 group by machine_id ;
-- select * from temp1 group by machine_id ;
