<?php
session_start();
$username = $_POST['username'] ?? '';
$password = $_POST['password'] ?? '';
$remember = $_POST['remember'] ?? '';
if(!isset($_SESSION[$username]) && isset($_SESSION[$password]))
{
    $_SESSION['user'] = $username;
    if(isset($remember))
    {
        setcookie('user', $username, time()+3600*24*7);
    }
}

if(isset($_COOKIE['user']))
{
    $_SESSION['user'] = $_COOKIE['user'];
}

if(isset($_SESSION['user']))
{
    header('Location: /0306221377_tuan6/index_main.php');
    exit();
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="" method="post">
        <label for="username">User:</label>
        <input type="text" name="username"> 
        <br>
        <label for="password">Password:</label> 
        <input type="password" name="password">
        <br>
        <input type="checkbox" name="remember"> Remember login?
        <br>
        <button>Login</button>
    </form>
</body>
</html>