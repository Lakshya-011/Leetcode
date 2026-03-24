CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
declare val int;
set val=N-1;
  RETURN (
      # Write your MySQL query statement below.
    select DISTINCT salary
    from Employee
    Order BY salary DESC
    limit 1 offset val
  );
END