# Write your MySQL query statement below


select b.book_id as book_id, title, author, genre, publication_year, total_copies as current_borrowers 
from library_books as l join borrowing_records as b on l.book_id = b.book_id  where return_date is null 
group by title having count(title) = total_copies order by count(title) desc , title asc