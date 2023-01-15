<?php

    
    $host="localhost";
    $dbName = "bestjobs";
    $userName = "root";
    $password = "";

    $con = new mysqli($host, $userName, $password, $dbName);

    if(mysqli_connect_errno()) {
        echo "Error: Could not connect to database";
        exit;
    } 


    $username = $_POST["username"];
    $password = $_POST["password"];
    $firstName = $_POST["firstName"];
    $lastName = $_POST["lastName"];
    $gender = $_POST["gender"];
    $nationality = $_POST["nationality"];
    $dob = $_POST["dob"];
    $email = $_POST["email"];
    $phoneNumber = $_POST["phoneNumber"];
    $address = $_POST["address"];
    $twitter = $_POST["twitter"];
    $facebook = $_POST["facebook"];
    $google = $_POST["google"];
    $ugCgpa = $_POST["ugCgpa"];
    $pgCgpa = $_POST["pgCgpa"];
    $project1 = $_POST["project1"];
    $project2 = $_POST["project2"];
    $project3 = $_POST["project3"];


    $sql = "insert into jobdata(username,password, firstName, lastName,gender,nationality,dob, email,phoneNumber,address,twitter,facebook,google,ugCgpa,pgCgpa,project1,project2,project3) values ('$username','$password','$firstName','$lastName','$gender','$nationality','$dob','$email','$phoneNumber','$address','$twitter','$facebook','$google','$ugCgpa','$pgCgpa','$project1','$project2','$project3')";

    $result = mysqli_query($con,$sql);
    // header("Location: bestJob.html?step=7");
?>