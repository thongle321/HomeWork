<?php
session_start();
if (isset($_COOKIE['username'])) {
    $_SESSION['username'] = $_COOKIE['username'];
}
if (isset($_SESSION['username'])) {
?>
<a href="logout.php">Đăng xuất</a>
<br>
<a href="account.php">Tài khoản</a>
<?php
} else {
?>
<a href="login.php">Đăng nhập</a>
<br>
<a href="register.php">Đăng ký</a>
<?php
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
</body>

</html>