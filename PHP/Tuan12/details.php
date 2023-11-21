<?php
$host = "localhost";
$dbname = "qlsp";
$username = "root";
$password = "";
try {
    $conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $id = $_GET['id'] ?? 0;
    $sql = "SELECT * FROM  san_pham WHERE id = :id";
    $stmt = $conn->prepare($sql);
    $stmt->bindValue(":id", $id);
    $stmt->execute();
    $dssp = $stmt->fetch(PDO::FETCH_ASSOC);
} catch (PDOException $e) {
    echo "Kết nối CSDL thất bại: " . $e->getMessage();
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
    <?php
    if ($dssp) {
        echo "<h1>Chi tiết sản phẩm</h1>";
        echo "Tên: " . $dssp['ten'] . "<br>";
        echo "Loại: " . $dssp['loai'] . "<br>";
        echo "Giá: "  . $dssp['gia'] . "<br>";
        echo "Mô tả: " . $dssp['mo_ta'] . "<br>";
    ?>
    <a href="edit.php?id=<?= $dssp['id'] ?>">Sửa</a>
    <a href="delete.php?id=<?= $dssp['id'] ?>">Xoá</a>
    <?php
    } else {
        echo "Không tìm thấy sản phẩm ";
    }

    ?>
</body>

</html>