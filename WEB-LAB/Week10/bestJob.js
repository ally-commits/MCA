var currentTab = 1;

let nextButton = document.getElementById("next")
let prevButton = document.getElementById("prev")

 
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
        nextButton.innerText = currentTab == 5 ? "Display Values" : "Submit Form";
    else
        nextButton.innerHTML = "Next";
 
    if(currentTab == 6) {
        document.getElementById("myForm").submit();
    }  
} 
 
 
renderTab(0);
