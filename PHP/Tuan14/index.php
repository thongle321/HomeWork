<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <h1>Trang chủ</h1>
    <?php
    if (isset($_COOKIE['usernane'])) {
        $_SESSION['usernane'] = $_COOKIE['usernane'];
    }
    if (isset($_SESSION['usernane'])) {
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

</body>

</html>