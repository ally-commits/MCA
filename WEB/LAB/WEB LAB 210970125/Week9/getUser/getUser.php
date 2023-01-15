<h2>AJAX RESPONSE</h2>
<?php
    $queryString = $_GET['q'];
    $con = mysqli_connect('localhost','root','','demo'); 
    if(!$con) {
        die('Could not connect:' . mysqli_error($con));
    }

    $sql = 'Select * from demotable where id=' . $queryString;
    $result = mysqli_query($con,$sql);

    echo "<table border=2 cellpadding=6 cellspacing=2>
            <tr>
                <th>Id</th>
                <th>Name</th>
                <th>Designation</th>
            </tr>
    ";

    while($row=mysqli_fetch_array($result)) {
        echo "<tr>";
        echo "<td>" . $row['id'] . "</td>";
        echo "<td>" . $row['name'] . "</td>";
        echo "<td>" . $row['designation'] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
    mysqli_close($con);
?>