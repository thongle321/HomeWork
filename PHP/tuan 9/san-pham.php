<?php
$d = $_GET['id'] ?? 0;
$host = "localhost";
$username = "root";
$password = "";
$dbname = "sanpham";
try {
    $conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    // thiết lập khi xảy ra lỗi thì tạo ra ngoại lệ (exeption) ​
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Kết nối CSDL thất bại: " . $e->getMessage();
    exit;
}
try {
    $sql = 'SELECT `Id`, `ten`, `loai`, `gia`, `hinh`, `mota` FROM `san_pham` WHERE `Id` = :id';
    $stmt = $conn->prepare($sql);
    $stmt->bindValue(':id', $id, PDO::PARAM_INT);
    $stmt->execute();
    $stmt->setFetchMode(PDO::FETCH_ASSOC);

    $dssp = $stmt->fetchAll();
} catch (PDOException $e) {
    echo "Loi " . $e->getMessage();
    exit;
}
$conn = NULL;
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

    ?>
</body>

</html>