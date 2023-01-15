<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Edit Record</title>
    <link rel="stylesheet" href="./style.css" />
</head>
<body>
    <?php
        include 'conn.php';
        if(isset($_GET["accesibleNumber"])) {
            $sql = "select * from books where accesibleNumber=".$_GET["accesibleNumber"];
            $result = mysqli_query($con,$sql);
 
            $record = mysqli_fetch_array($result);
    ?>
        <div class="container">
            <h1>Edit Record</h1>
            
            <form action="#" method="POST" >
                BookTitle: <input type="text" name="title" value="<?php echo $record["title"]; ?>" /> <br />
                Authors: <input type="text" name="authors" value="<?php echo $record["authors"]; ?>" /> <br />
                Edition: <input type="text" name="edition" value="<?php echo $record["edition"]; ?>" /> <br />
                Publisher: <input type="text" name="publisher" value="<?php echo $record["publisher"]; ?>" /> <br />
                <input name="accesibleNumber" type="hidden" value="<?php echo $record["accesibleNumber"]; ?>"/>
                <input type="submit" value="Update Record" name="submit"/>
            </form>
        </div>
        <?php  

            if(isset($_POST["submit"])) {
                $title = $_POST['title'];
                $authors = $_POST['authors'];
                $edition = $_POST['edition'];
                $publisher = $_POST['publisher'];
                $accesibleNumber = $_POST['accesibleNumber'];

                $sql = "update books set title='$title', authors='$authors', edition='$edition', publisher='$publisher' where accesibleNumber='$accesibleNumber'";
                $result = mysqli_query($con,$sql);
                header("Location: index.php");
            }
        ?>
    <?php
        } else {
            echo "Invalid Request For Update";
        }
    ?>
</body>
</html>