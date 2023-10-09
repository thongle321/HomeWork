<?php
session_start();
if(!isset($_SESSION['user']))
{
    header('Location: /0306221377_tuan6/index_login.php');
    exit();
}
$user = $_SESSION['user'];
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>    
    <h1> Hello <?=$user?></h1> <a href="index_logout.php">Logout</a>
</body>
</html>