# Write your MySQL query statement below


select if((id=(select max(id) from seat) and id%2 = 1),id,if(id%2=0,id-1,id+1)) as id, student from seat order by id