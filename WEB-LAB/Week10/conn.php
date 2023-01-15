<?php
    $host="localhost";
    $dbName = "bookStore";
    $userName = "root";
    $password = "";

    $con = new mysqli($host, $userName, $password, $dbName);

    if(mysqli_connect_errno()) {
        echo "Error: Could not connect to database";
        exit;
    } 
?>