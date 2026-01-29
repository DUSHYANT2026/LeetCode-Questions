-- CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
-- BEGIN
--   SET N = N-1;
--   RETURN (
--     SELECT DISTINCT salary from Employee order by salary desc limit 1 offset N
--   );
-- END



-- CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
-- BEGIN
--   DECLARE ans INT;
--   SET N = N-1;
--   SELECT DISTINCT salary INTO ans FROM Employee ORDER BY salary DESC 
--   LIMIT 1 OFFSET N;
--   RETURN ans;
-- END


CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N = N - 1;
  RETURN (
      SELECT DISTINCT salary 
      FROM Employee 
      ORDER BY salary DESC 
      LIMIT 1 OFFSET N
  );
END