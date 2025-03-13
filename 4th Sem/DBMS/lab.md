# DBMS Lab
#### Subject Code: BCS403
## Contents:  
1: Create a table called Employee & execute the following.
Employee (EMPNO, ENAME, JOB, MANAGER_NO, SAL, COMMISSION)
1. Create a user and grant all permissions to theuser.
2. Insert the any three records in the employee table contains attributes
EMPNO,ENAME JOB, MANAGER_NO, SAL, COMMISSION and use rollback.
Check the result.
3. Add primary key constraint and not null constraint to the employee table.
4. Insert null values to the employee table and verify the result.
##
2: Create a table called Employee that contain attributes EMPNO,ENAME,JOB, MGR,SAL &
execute the following.
1. Add a column commission with domain to the Employee table.
2. Insert any five records into the table.
3. Update the column details of job
4. Rename the column of Employ table using alter command.
5. Delete the employee whose Empno is 105.
##
3: Queries using aggregate functions(COUNT,AVG,MIN,MAX,SUM),Group by,Orderby.
Employee(E_id, E_name, Age, Salary)
1. Create Employee table containing all Records E_id, E_name, Age, Salary.
2. Count number of employee names from employee table
3. Find the Maximum age from employee table.
4. Find the Minimum age from employee table.
5. Find salaries of employee in Ascending Order.
6. Find grouped salaries of employees.
##
4: Create a row level trigger for the customers table that would fire for INSERT or UPDATE or DELETE operations performed on the CUSTOMERS table. This trigger will display the salary difference between the old & new Salary.
CUSTOMERS(ID,NAME,AGE,ADDRESS,SALARY)
##
5: Create cursor for Employee table & extract the values from the table. Declare the variables,Open the cursor & extract the values from the cursor. Close the cursor. Employee(E_id, E_name, Age, Salary)
##
6: Write a PL/SQL block of code using parameterized Cursor, that will merge the data available in the newly created table N_RollCall with the data available in the table O_RollCall. If the data in the first table already exist in the second table then  that data should be skipped.
##
7: Install an Open Source NoSQL Data base MangoDB & perform basic CRUD(Create, Read,
Update & Delete) operations. Execute MangoDB basic Queries using CRUD operations.
##
# Program 1
## Create a table called Employee & execute the following. \n Employee (EMPNO, ENAME, JOB, MANAGER_NO, SAL, COMMISSION)

# Program:
DELETE FROM table_name WHERE condition;

