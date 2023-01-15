<!DOCTYPE html>
<html lang="en">
<head> 
    <title>Book Store</title>
    <link rel="stylesheet" href="./style.css" />
</head>
<body>
    <div class="container">
        <?php   
            include 'conn.php';
            $sql = 'select * from books';
            $result = mysqli_query($con,$sql);
        ?>
            <div class="content">
                <h1>Book Store</h1>
                <a href="addRecord.php">Add Book</a>
            </div>
            <table border="2">
                <tr>
                    <th>Accessible Number</th>
                    <th>Title</th>
                    <th>Authors</th>
                    <th>Edition</th>
                    <th>Publisher</th>
                    <th>Action</th>
                </tr>

        <?php
            if (mysqli_num_rows($result) > 0 ) {
                while($row = mysqli_fetch_array($result)) {
                    echo "<tr>";
                    echo "<td>" . $row["accesibleNumber"] . "</td>";
                    echo "<td>" . $row["title"] . "</td>";
                    echo "<td>" . $row["authors"] . "</td>";
                    echo "<td>" . $row["edition"] . "</td>";
                    echo "<td>" . $row["publisher"] . "</td>";
                    echo 
                        "<td>
                            <a href='editRecord.php?accesibleNumber=".$row["accesibleNumber"]."'>Edit</a>
                            <a href='#' id=".$row["accesibleNumber"]." onclick={handleConfirmDelete(this)}>Delete</a>
                        </td>";
                    echo "</tr>";
                }
                echo "</table>";
            } else {
                echo "</table>";
                echo "No Records Found";
            }
        ?>

        <script>
            function handleConfirmDelete(e) {
                if(confirm("You Sure You want to delete this record?")) {
                    window.location.href = "deleteRecord.php?accesibleNumber=" + e.id;
                } 
            }
        </script>
    </div>

</body>
</html>

