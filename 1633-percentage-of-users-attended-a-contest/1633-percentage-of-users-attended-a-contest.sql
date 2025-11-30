# Write your MySQL query statement below


with temp as
(
    select contest_id, round(( count(u.user_id)/(select count(user_id) from users) ) * 100 , 2) as percentage 
    from users u join register r on u.user_id = r.user_id  group by contest_id
)

select * from temp order by percentage desc, contest_id