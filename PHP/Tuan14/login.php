<?php
require_once("DB.php");
session_start();

if (isset($_SESSION['usernane'])) {
    header("Location: index.php");
    exit;
}
$error = "";
if ($_SERVER['REQUEST_METHOD'] == "POST") {
    $usernane = trim($_POST['usernane'] ?? '');
    $password = trim($_POST['password'] ?? '');
    $sql = "SELECT * FROM tai_khoan WHERE usernane = :usernane AND password = :password";
    $stmt = $conn->prepare($sql);
    $stmt->bindValue(":usernane", $usernane);
    $stmt->bindValue(":password", $password);
    $stmt->execute();
    $user = $stmt->fetch();
    if ($user > 0) {
        $_SESSION['usernane'] = $usernane;
        if (isset($_POST['remember'])) {
            setcookie("usernane", $usernane, time() + 3600 * 24 * 7);
        }
        header("Location: index.php");
        exit;
    } else {
        $error = "Sai tài khoản hoặc mật khẩu";
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
    <h1>Đăng nhập</h1>
    <form action="" method="post">
        <label for="usernane">Username</label>
        <input type="text" name="usernane" required> <br>
        <br>
        <label for="password">Password</label>
        <input type="password" name="password" required>
        <br>
        <label for="remember">Ghi nhớ đăng nhập</label>
        <input type="checkbox" name="remember">
        <br>
        <input type="submit" value="Đăng nhập">
    </form>
    <?php
    echo "<br>";
    echo $error;
    ?>
</body>

</html>