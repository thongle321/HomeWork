<?php
require_once("DB.php");
session_start();

if (!isset($_SESSION['usernane'])) {
    header("Location: login.php");
    exit;
}
$success = "";
$errorpass = "";
if ($_SERVER['REQUEST_METHOD'] == "POST") {
    $password = trim($_POST['password'] ?? '');
    if (strlen($password) >= 6 && strlen($password) <= 60) {
        $sql = "UPDATE tai_khoan SET password = :password WHERE usernane = :usernane";
        $stmt = $conn->prepare($sql);
        $stmt->bindValue(":password", $password);
        $stmt->bindValue(":usernane", $_SESSION['usernane']);
        $stmt->execute();
        $success = "Đổi mật khẩu thành công";
    } else {
        $errorpass = "Mật khẩu không đủ ký tự từ 6 đến 60";
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
    <h1>Tài khoản</h1>
    <form action="" method="post">
        <label for="password">New Password</label>
        <input type="password" name="password" required>
        <br>
        <input type="submit" value="Đồng ý">
    </form>
    <?php
    echo "<br>";
    echo $success;
    echo $errorpass;
    ?>
</body>

</html>