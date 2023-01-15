<!DOCTYPE html>
<html lang="en">
<head> 
    <title>Cookie</title>
</head>
<body>
    <?php
        if(isset($_COOKIE["lastVisited"])) {
            echo "Welcome Back <br />Your Last Visit was " . $_COOKIE["lastVisited"];
        } else {
            echo "Welcome!<br /> Visiting for the First Time";
        }
 
        setcookie("lastVisited",date("F j, Y, g:i a"), time() + (86400 * 30),"/");
    ?>
</body>
</html>