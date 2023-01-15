const { MongoClient, ObjectID } = require('mongodb');

const url = 'mongodb+srv://dix:v3y2lT1xM5ZZwYPs@cluster0.zg4jw.mongodb.net/?retryWrites=true&w=majority';
const client = new MongoClient(url);

const dbName = 'resturant';
const data = require("./data.json")
const foodData = require("./product.json")

function randomIntFromInterval(min, max) { // min and max included 
    return Math.floor(Math.random() * (max - min + 1) + min)
}

async function main() {
    await client.connect(); 
    const db = client.db(dbName);
    console.log("orders")
    const collection = db.collection('products');
  
    let data = await collection.deleteMany({ price:{$lte: 50}});

    console.log(data);  

    return 'done.';
}

main()
    .then(console.log)
    .catch(console.error)
    .finally(() => {});