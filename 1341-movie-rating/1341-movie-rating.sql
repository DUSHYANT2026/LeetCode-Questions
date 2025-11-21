# Write your MySQL query statement below


(select name as results 
from MovieRating m join users u on m.user_id = u.user_id 
group by name order by count(movie_id) desc, name limit 1)

union all 

(select title as results
from MovieRating m join Movies mm on m.movie_id = mm.movie_id 
group by m.movie_id order by  ( sum(if(month(created_at) = 2,rating,0)) / sum(if(month(created_at) = 2, 1 , 0)) ) desc, title asc limit 1)
