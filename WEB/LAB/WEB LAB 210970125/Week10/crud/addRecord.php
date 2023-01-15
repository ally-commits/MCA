<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add Record</title>
    <link rel="stylesheet" href="./style.css" />
</head>
<body>
    <div class="container">
        <h1>Add Record</h1>
        <form action="#" method="POST" >
            BookTitle: <input type="text" name="title" /> <br />
            Authors: <input type="text" name="authors" /> <br />
            Edition: <input type="text" name="edition" /> <br />
            Publisher: <input type="text" name="publisher" /> <br />

            <input type="submit" value="Add Record" name="submit"/>
        </form>
    </div>
    <?php 
        include 'conn.php';
        if(isset($_POST["submit"])) {
            $title = $_POST['title'];
            $authors = $_POST['authors'];
            $edition = $_POST['edition'];
            $publisher = $_POST['publisher'];

            $sql = "insert into books(title,authors, edition, publisher) values('$title','$authors','$edition','$publisher')";
            $result = mysqli_query($con,$sql);
            header("Location: index.php");
        }


    ?>
</body>
</html>