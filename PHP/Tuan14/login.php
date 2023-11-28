<?php
session_start();
$host = "localhost";
$dbname = "qlsv";
$username = "root";
$password = "";
try {
    $conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    if (isset($_SESSION['usernane'])) {
        header("Location: index.php");
        exit;
    }
    $errorMessage = "";
    if ($_SERVER['REQUEST_METHOD'] == "POST") {
        $usernane = trim($_POST['usernane'] ?? '');
        $password = trim($_POST['password'] ?? '');
        $sql = "SELECT * FROM tai_khoan WHERE usernane = :usernane AND password = :password";
        $stmt = $conn->prepare($sql);
        $stmt->bindValue(":usernane", $usernane);
        $stmt->bindValue(":password", $password);
        $stmt->execute();
        $user = $stmt->fetchAll(PDO::FETCH_ASSOC);
        if ($user > 0) {
            $_SESSION['usernane'] = $usernane;
            if (isset($_POST['remember'])) {
                setcookie("usernane", $usernane, time() + 3600 * 24 * 7);
            }
            header("Location: index.php");
            exit;
        } else {
            $errorMessage = "Sai tài khoản hoặc mật khẩu";
        }
    }
} catch (PDOException $e) {
    echo "Kết nối CSDL thất bại" . $e->getMessage();
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
        <label for="usernane">usernane</label>
        <input type="text" name="usernane" required> <br>
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