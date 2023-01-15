const fs = require("fs");

(() => {
    fs.readFile('one.text', 'utf8', (err, data) => {
        if (err) {
            console.error(err);
            return;
        }
        let emailList = [];

        emailList = data.split('\n')

        let countEmail = 0;
        emailList.forEach(val => {
            if (val.includes("skudszwsxfxb.in")) {
                countEmail++;
            }
        })

        console.log("EMAIL COUNT:" + countEmail)
    });
})();