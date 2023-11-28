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
    if ($_SERVER['REQUEST_METHOD'] == "POST") {
        $usernane = trim($_POST['usernane'] ?? '');
        $password = trim($_POST['password'] ?? '');
        if (strlen($usernane) < 6 || strlen($usernane) > 32 || strlen($password) < 6 || strlen($password) > 60) {
            echo "Tài khoản hoặc mật khẩu không đủ ký tự";
        } else {
            $sql = "SELECT * FROM tai_khoan WHERE usernane = :usernane";
            $stmt = $conn->prepare($sql);
            $stmt->bindValue(":usernane", $usernane);
            $stmt->execute();
            $user = $stmt->fetchAll(PDO::FETCH_ASSOC);
            if ($user) {
                echo "Tên usernane đã tồn tại";
            } else {
                $sql = "INSERT INTO tai_khoan (usernane, password) VALUES(:usernane, :password)";
                $stmt = $conn->prepare($sql);
                $stmt->bindValue(":usernane", $usernane);
                $stmt->bindValue(":password", $password);
                $stmt->execute();
                echo "Đăng ký thành công";
            }
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
    <div class="form">
        <form action="" method="post">
            <label for="usernane">username</label>
            <input type="text" name="usernane" required> <br>
            <br>
            <label for="password">Password</label>
            <input type="password" name="password" required>
            <br>
            <input type="submit" value="Đăng ký">
        </form>
    </div>

</body>

</html>