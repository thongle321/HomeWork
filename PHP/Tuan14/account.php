<?php
require_once("DB.php");
session_start();

if (!isset($_SESSION['username'])) {
    header("Location: login.php");
    exit;
}
if ($_SERVER['REQUEST_METHOD'] == "POST") {
    $password = trim($_POST['password'] ?? '');
    if (strlen($password) >= 6 || strlen($password) <= 60) {
        $sql = "UPDATE tai_khoan SET password = :password WHERE username = :username";
        $stmt = $conn->prepare($sql);
        $stmt->bindValue(":password", $password);
        $stmt->bindValue(":username", $_SESSION['username']);
        $stmt->execute();
        echo "Đổi mật khẩu thành công";
    } else {
        echo "Mật khẩu không đúng ký tự từ 6 đến 60";
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
</head>

<body>
    <form action="" method="post">
        <label for="password">New Password</label>
        <input type="password" name="password" required>
        <br>
        <input type="submit" value="Đồng ý">
    </form>
</body>

</html>