<?php
    session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head> 
    <title>SESSION PAGE VISIT COUNT</title>
</head>
<body>
    <?php
        if(isset($_SESSION['pageVisit'])) {
            $_SESSION['pageVisit']  += 1;
        } else {
            $_SESSION['pageVisit'] =  1;
        }
        echo "Page Visit Count:" . $_SESSION['pageVisit'];
    ?>
</body>
</html>