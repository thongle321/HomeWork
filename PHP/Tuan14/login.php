<?php
require_once("DB.php");
session_start();

if (isset($_SESSION['username'])) {
    header("Location: index.php");
    exit;
}
$errorMessage = "";
if ($_SERVER['REQUEST_METHOD'] == "POST") {
    $username = trim($_POST['username'] ?? '');
    $password = trim($_POST['password'] ?? '');
    $sql = "SELECT * FROM tai_khoan WHERE username = :username AND password = :password";
    $stmt = $conn->prepare($sql);
    $stmt->bindValue(":username", $username);
    $stmt->bindValue(":password", $password);
    $stmt->execute();
    $user = $stmt->fetchAll(PDO::FETCH_ASSOC);
    if ($user > 0) {
        $_SESSION['username'] = $username;
        if (isset($_POST['remember'])) {
            setcookie("username", $username, time() + 3600 * 24 * 7);
        }
        header("Location: index.php");
        exit;
    } else {
        $errorMessage = "Sai tài khoản hoặc mật khẩu";
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
        <label for="username">username</label>
        <input type="text" name="username" required> <br>
        <br>
        <label for="password">Password</label>
        <input type="password" name="password" required>
        <br>
        <input type="checkbox" name="remember"> Remember login?
        <br>
        <input type="submit" value="Đăng nhập">
    </form>
    <?php
    echo $errorMessage;
    ?>
</body>

</html>