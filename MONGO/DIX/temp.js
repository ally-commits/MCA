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
    const collection = db.collection('products');
    // collection.deleteMany({});


    for await (let topData of foodData) {
        for await (let productData of topData.foodItems) {
            let coll = db.collection("restuarants");
            let r = (Math.random() + 1).toString(36).substring(7);
            let valueData = await coll
                .find()
                .skip(randomIntFromInterval(0, 1179))
                .limit(1)
                .toArray();

            let dataValue = valueData[0];

            await collection.insertOne({
                name: productData.foodName,
                foodType: productData.foodType,
                calories: productData.calories,
                resturantId: ObjectID(valueData._id),
                price: randomIntFromInterval(0, 500)
            })
        }
    }

    // return 'done.';
}

main()
    .then(console.log)
    .catch(console.error)
    .finally(() => { });