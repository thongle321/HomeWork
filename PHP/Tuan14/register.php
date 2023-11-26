<?php
require_once("DB.php");
session_start();
if (isset($_SESSION['username'])) {
    header("Location: index.php");
    exit;
}
if ($_SERVER['REQUEST_METHOD'] == "POST") {
    $username = trim($_POST['username'] ?? '');
    $password = trim($_POST['password'] ?? '');
    if (strlen($username) >= 6 || strlen($username) <= 32 || strlen($password) >= 6 || strlen($password) <= 60) {
        echo "Tài khoản hoặc mật khẩu không đủ ký tự";
    } else {
        $sql = "SELECT * FROM tai_khoan WHERE username = :username";
        $stmt = $conn->prepare($sql);
        $stmt->bindValue(":username", $username);
        $stmt->execute();
        $user = $stmt->fetch();
        if ($user) {
            echo "Tên username đã tồn tại";
        } else {
            $sql = "INSERT INTO tai_khoan (username, password) VALUES(:username, :password)";
            $stmt = $conn->prepare($sql);
            $stmt->bindValue(":username", $username);
            $stmt->bindValue(":password", $password);
            $stmt->execute();
            echo "Đăng ký thành công";
        }
    }
}
$conn = null;

?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="style.css">
</head>

<body>
    <div class="register">
        <h1>Đăng nhập</h1>
        <form action="" method="post">
            <label for="username">Username</label>
            <input type="text" name="username" required>
            <label for="password">Password</label>
            <input type="password" name="password" required>
            <input type="submit" value="Đăng ký">
        </form>
    </div>

</body>

</html>