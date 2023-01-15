<!DOCTYPE html>
<html lang="en">
<head> 
    <title>Upload Resume</title>
    <style>
        * {
            padding: 0px;
            margin: 0px;
            box-sizing: border-box;
        }
        .container {
            display: flex;
            justify-content: center;
            align-items: center;
            width: 100vw;
            height: 100vh;
        }
        .content {
            width: 500px;
            height: 500px;
            padding: 40px;
            border: 1px solid crimson;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="content">
            <form action="" method="POST" enctype="multipart/form-data">
                <input type="file" name="resume" /> <br /><br />
                <input type="submit" name="submit" />
            </form>

            <?php 
                if($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_FILES['resume'])) {
                    $errors = array();
                    $fileName = $_FILES['resume']['name'];
                    $fileSize = $_FILES['resume']['size'];
                    $fileTemp = $_FILES['resume']['tmp_name'];
                    $fileType = $_FILES['resume']['type'];
                    
                    $temp = explode('.',$_FILES['resume']['name']);
                    $fileExtension = end($temp);

                    $acceptedExtensions = array("jpeg","jpg","pdf");
                    
                    if(in_array($fileExtension, $acceptedExtensions) === false) {
                        $errors[] = $fileExtension . " Not allowed Please upload valid extension files";
                    }
                    if($fileSize > 21097152) {
                        $errors[] = "File Size must be less than 2MB";
                    }

                    if(empty($errors) == true) {
                        move_uploaded_file($fileTemp , "images/".$fileName);
                        echo "Success";

                        echo "<ul>
                                <li>Temp Location:" . $fileTemp . "</li>
                                <li>Sent File :" . $fileName . "</li>
                                <li>File Size :" . $fileSize . "</li>
                                <li>File Type :" . $fileType . "</li>
                        ";
                    } else {
                        print_r($errors);
                    }
                }  
            ?>
        </div>
    </div>
</body>
</html>