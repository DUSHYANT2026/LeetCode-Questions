# Write your MySQL query statement below



with temp as
(
select b.book_id, title, author, genre, pages, max(session_rating) as a, min(session_rating) as b , sum(if(session_rating>=4 , 1, 0)) as x, 
sum(if(session_rating <= 2 ,1,0)) as y , count(b.book_id) as z from books b join reading_sessions r on b.book_id = r.book_id group by b.book_id 
)

select book_id, title, author, genre, pages, (a-b) as rating_spread ,  round(((x+y)/z),2) as polarization_score 
from temp where x > 0 and y > 0 and round(((x+y)/z),2)>= 0.6
order by round(((x+y)/z),2) desc , title desc;



