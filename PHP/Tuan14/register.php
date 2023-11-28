<?php
require_once("DB.php");
session_start();
if (isset($_SESSION['usernane'])) {
    header("Location: index.php");
    exit;
}
$error = "";
$success = "";
$errorname = "";
$errorpass = "";
if ($_SERVER['REQUEST_METHOD'] == "POST") {
    $usernane = trim($_POST['usernane'] ?? '');
    $password = trim($_POST['password'] ?? '');
    if (strlen($usernane) < 6 || strlen($usernane) > 32) {
        $errorname = "Username phải đủ ký tự từ 6 đến 32";
    }

    if (strlen($password) < 6 || strlen($password) > 60) {
        $errorpass = "Mật khẩu phải đủ ký tự từ 6 đến 60";
    }

    if ($errorname || $errorpass) {
        $error = $errorname . ($errorname && $errorpass ? " và " : "") . $errorpass;
    } else {
        $sql = "SELECT * FROM tai_khoan WHERE usernane = :usernane";
        $stmt = $conn->prepare($sql);
        $stmt->bindValue(":usernane", $usernane);
        $stmt->execute();
        $user = $stmt->fetchAll(PDO::FETCH_ASSOC);
        if ($user) {
            $error = $error . "Tài khoản đã tồn tại";
        } else {
            $sql = "INSERT INTO tai_khoan (usernane, password) VALUES(:usernane, :password)";
            $stmt = $conn->prepare($sql);
            $stmt->bindValue(":usernane", $usernane);
            $stmt->bindValue(":password", $password);
            $stmt->execute();
            $success = "Đăng ký thành công";
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
</head>

<body>
    <h1>Đăng Ký</h1>
    <form action="" method="post">
        <label for="usernane">Username</label>
        <input type="text" name="usernane" required>
        <label for="password">Password</label>
        <input type="password" name="password" required>
        <input type="submit" value="Đăng ký">
    </form>
    <?php
    echo "<br>";
    echo $error;
    echo $success;
    ?>
</body>

</html>