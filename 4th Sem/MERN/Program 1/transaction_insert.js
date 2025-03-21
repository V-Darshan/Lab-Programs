// Step 1: Connect to MongoDB
const MongoClient = require("mongodb").MongoClient;
const fs = require("fs");

// Connection URL
const url = "mongodb://localhost:27017";

// Database Name
const dbName = "usermanaged";

// File path for transactions.json
const transactionsFilePath = "transactions.json";

// Connect to MongoDB
MongoClient.connect(url, function (err, client) {
  if (err) {
    console.error("Failed to connect to MongoDB:", err);
    return;
  }
  console.log("Connected successfully to server");

  // Access the usermanaged database
  const db = client.db(dbName);

  // Create or access the transactions collection
  const collection = db.collection("transactions");

  // Drop the collection if it already exists
  collection
    .drop()
    .catch((err) => {
      // Ignore drop errors if collection doesn't exist
      if (err.code !== 26) {
        console.error("Error dropping collection:", err);
      }
    })
    .then(() => {
      // Load data from transactions.json file
      const transactionsData = JSON.parse(
        fs.readFileSync(transactionsFilePath, "utf8")
      );

      // Insert data into the collection
      return collection.insertMany(transactionsData);
    })
    .then((result) => {
      console.log(
        `Inserted ${result.insertedCount} documents into the collection`
      );
      client.close();
    })
    .catch((err) => {
      console.error("Error inserting documents:", err);
      client.close();
    });
});
