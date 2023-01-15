<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Delete Record</title>
    <link rel="stylesheet" href="./style.css" />
</head>
<body>
    <?php
        include 'conn.php';
        if(isset($_GET["accesibleNumber"])) {  
            $accesibleNumber = $_GET['accesibleNumber'];
            $sql = "delete from books where accesibleNumber='$accesibleNumber'";
            $result = mysqli_query($con,$sql);
            header("Location: index.php"); 
        ?>
    <?php
        } else {
            echo "Invalid Request For Update";
        }
    ?>
</body>
</html>