var currentTab = 1;

let nextButton = document.getElementById("next")
let prevButton = document.getElementById("prev")

let userData = {
    step1: { username: "", password: "", cpassword:""},
    step2: { firstName: "", lastName: "", gender: "", nationality: "", dob: "" },
    step3: { email: "", phoneNumber: "", address: ""},
    step4: { twitter: "", facebook: "", google: ""},
    step5: { ugCgpa: "", pgCgpa: "", project1: "", project2: "", project3: "" },
}
const renderTab = (value) => {
    currentTab += value; 
    let arr = document.getElementsByClassName("contentContainer");
    let indicators = document.getElementsByClassName("indicator");

    Object.values(arr).forEach(val => {
        val.style.display = "none";
        if(val.className.includes("tab" + currentTab)) {
            val.style.display = "flex";
        }
    })
    Object.values(indicators).forEach((val,index) => {
        val.classList.remove("active");
        if((index+1) == currentTab) {
            val.classList.add("active");
        }
    })
    if(currentTab == 1)
        prevButton.style.visibility = "hidden";
    else   
        prevButton.style.visibility = "visible";

    if(currentTab >= 5)
        nextButton.innerText = "Submit Form";
    else
        nextButton.innerHTML = "Next";
  
    if(currentTab == 6) 
        document.getElementById("footer").style.display = "none";
} 
 

const getValidation = (stepCountArg) => {
    let stepCount = stepCountArg + currentTab - 1;
    
        let queryString = "?";
        Object.keys(userData["step" + stepCount]).forEach(key => {
            queryString += key + "=" + document.getElementById(key).value + "&";
            document.getElementById(key + "-error").innerText = "";
        })
        queryString += "step=" + "step" + stepCount;


        if (window.XMLHttpRequest) {
            xhttp = new XMLHttpRequest();
        } else {
            xhttp = new ActiveXObject("Microsoft.XMLHTTP");
        }
        xhttp.onreadystatechange = function () {
            if (xhttp.readyState == 4 && xhttp.status == 200) {
                let responseData = JSON.parse(xhttp.response);
                if (responseData.length == 0) {
                    if (stepCount < 5) { 
                        renderTab(stepCountArg)
                    } else {
                        submitForm(stepCountArg)
                    }
                } else {
                    responseData.forEach(val => {
                        document.getElementById(val.key + "-error").innerText = val.message;
                    })
                }
            }
        }

        xhttp.open("GET", "bestJob.php" + queryString, true);
        xhttp.send();
}

function submitForm(stepCountArg) {
    let queryString = "";
    Object.keys(userData).forEach(keyP => {
        let data = userData[keyP];
        Object.keys(data).forEach(key => {
            queryString += key + "=" + document.getElementById(key).value + "&";
            document.getElementById(key + "-error").innerText = "";
        })
    })
    queryString += "&submit=SUBMIT";

    if (window.XMLHttpRequest) {
        xhttp = new XMLHttpRequest();
    } else {
        xhttp = new ActiveXObject("Microsoft.XMLHTTP");
    }
    xhttp.onreadystatechange = function () {
        if (xhttp.readyState == 4 && xhttp.status == 200) {
            renderTab(stepCountArg)
        }
    }
    
    xhttp.open("POST", "bestJob.php", true);
    xhttp.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xhttp.send(queryString);
}
 
renderTab(0);
