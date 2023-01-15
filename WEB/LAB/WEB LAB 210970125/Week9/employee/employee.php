<?php
    $myFile = "employee.json";
    $arrData = array();

    try {
        $formData = array(
            'firstName' => $_POST['firstName'],
            'lastName' => $_POST['lastName'],
            'email' => $_POST['email'],
            'mobile' => $_POST['mobile'],
        );
        $jsonData = file_get_contents($myFile);

        $arrData = json_decode($jsonData,true);
        array_push($arrData,$formData);
        $jsonData = json_encode($arrData,JSON_PRETTY_PRINT);

        if(file_put_contents($myFile,$jsonData)) {
            echo "Data Saved SuccessFully";
            $arrData = json_decode($jsonData, true);

            echo "<br /> Imformation Entered <br />";
            echo "<table border=2 cellpadding=6 cellspacing=2>
                    <tr>
                        <th>First Name</th>
                        <th>Last Name</th>
                        <th>Email</th>
                        <th>Mobile</th>
                    </tr>
            ";
            foreach($arrData as $x => $x_value) {
                echo "<tr>";
                echo "<td>" . $x_value['firstName'] . "</td>";
                echo "<td>" . $x_value['lastName'] . "</td>";
                echo "<td>" . $x_value['email'] . "</td>";
                echo "<td>" . $x_value['mobile'] . "</td>";
                echo "</tr>";
            }
            echo "</table>";
        } else {
            echo "Error";
        }
    } catch(Exception $e) {
        echo "Caught Exception:" . $e.getMessage();
    }
?>