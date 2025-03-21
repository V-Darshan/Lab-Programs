# BDSL456C : MERN
# Insctuctions for MERN Lab

## Programs:
1. Using MongoDB, create a collection called transactions in database usermanaged (drop if it already exists)
and bulk load the data from a json file, transactions.json
b. Upsert the record from the new file called transactions_upsert.json in Mongodb.
##
2. Query MongoDB with Conditions: [Create appropriate collection with necessary documents to answer the
query]
a Find any record where Name is Somu
b. Find any record where total payment amount (Payment.Total) is 600.
c. Find any record where price (Transaction.price) is between 300 to 500.
d. Calculate the total transaction amount by adding up Payment.Total in all records.
##
3. a. Write a program to check request header for cookies.
b. write node.js program to print the a car object properties, delete the second property and get length of
the object.
##
4. a. Read the data of a student containing usn, name, sem, year_of_admission from node js and store it in
the mongodb
b. For a partial name given in node js, search all the names from mongodb student documents created in
Question(a)
##
5. Implement all CRUD operations on a File System using Node JS
##
6. Develop the application that sends fruit name and price data from client side to Node.js server using Ajax
##
7. Develop an authentication mechanism with email_id and password using HTML and Express JS (POST
method)
##
8. a. Develop two routes: find_prime_100 and find_cube_100 which prints prime numbers less than 100 and
cubes less than 100 using Express JS routing mechanism
##
9. a. Develop a React code to build a simple search filter functionality to display a filtered list based on the
search query entered by the user.
##
10. a. Develop a React code to collect data from rest API. 
## Program 1 :
1. Create a sample json file with the name transctions.json
2. Import data into MongoDB Compass 
3. Select insert doc and type the data in json type (if any error : things might be missing)
## Program 2:
Didnt teach
## Program 3a:
1. Install Node.js app (node.js download)
2. Check wheather node js is installed (node -v)
3. Create package.json and problem3_a.js & run problem3_a.js file (node problem_3a.js)
4. Open postman app and send info to website and it will appear 
5. Go to headers section and then type url, key, value(value can be any msg)
6. The message will appear in cmd
## Program 3b:
1. Install express.js (npm install express) 
2. Create package.json problem3_b.js and run the file(if package is already there the no need)
2. Type in url and add "/api/car" (get http://localhost:3000/api/car)
2. Select delete option insted of get and run (delete http://localhost:3000/api/car/1)
3.then again get to show the info is deleted (get http://localhost:3000/apu/car)
## Program 5:
1. Create a.js 
2. uncomment create and run the file
3. Uncomment read and run the file
4. Uncomment append and run the file
5. Uncomment read and run the file
6. Uncomment update and run the file
7. Uncomment read and run the file
8. Uncomment delete and run the file

###### Output:
###### File created successfully.


###### File content: This is a sample text file.

###### Data appended to file successfully.

###### File content: This is a sample text file. Additional data appended.

###### File updated successfully.

###### File content: This is updated content.

###### File deleted successfully.


## Program 8:
1. Create package.json & server.js and run the file
2. Open Postman add to url "find_prime_100" (get http://localhost:3000/find_prime_100) 
3. Then replace the url with "find_cube_100" (get http://localhost:3000/find_cube_100) 
## Program 7:
1. Create 2 folders named server and client 
2. In server folder create server.js and package.json
3. In client folder create src and public folders
4. In src create the files app.css & app.js(if any error comes type "npm install react-scripts --save")
5. run the server.js file (node server.js)
6. goto client folder open cmd and there run the program (npm start)
7. Register using email id and password and login using same data (hi@example.com 123)

## Program 9:
1. Create client folder and then create
2. run the program (npm start)
3. Search in search bar and then filter items
## Program 6 :
1. Create 2 folders named server and client 
2. In server folder create server.js and package.json
3. In client folder create src and public folders
4. In src create the files app.css & app.js(if any error comes type "npm install react-scripts --save")
5. run the server.js file (node server.js)
6. goto client folder open cmd and there run the program (npm start)
7. When you type values in wesite the same values will be appearing in cmd
## Program 10 :
1. Create client folder and then create
2. run the program (npm start)
3. click on fetch data and it will be displayed on website
