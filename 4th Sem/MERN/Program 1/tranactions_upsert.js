// Step 1: Connect to MongoDB
const MongoClient = require("mongodb").MongoClient;
const fs = require("fs");

// Connection URL
const url = "mongodb://localhost:27017";

// Database Name
const dbName = "usermanaged";
// File path for transactions_upsert.json
const transactionsUpsertFilePath = "transactions_upsert.json";

MongoClient.connect(url, function (err, client) {
  if (err) {
    console.error("Failed to connect to MongoDB:", err);
    return;
  }

  console.log("Connected successfully to server");

  const db = client.db(dbName);
  const collection = db.collection("transactions");

  // Load data from transactions_upsert.json file
  const transactionsUpsertData = JSON.parse(
    fs.readFileSync(transactionsUpsertFilePath, "utf8")
  );

  // Upsert each record
  transactionsUpsertData.forEach((record) => {
    const filter = { _id: record._id };
    const update = { $set: record };
    collection
      .updateOne(filter, update, { upsert: true })
      .then((result) => {
        console.log(`Upserted document with ID ${record._id}`);
      })
      .catch((err) => {
        console.error("Error upserting document:", err);
      });
  });

  client.close();
});
