<?php
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
    $sql = 'SELECT * FROM san_pham';
    $stmt = $conn->prepare($sql);
    $stmt->execute();
    $stmt->setFetchMode(PDO::FETCH_ASSOC);

    $dssp = $stmt->fetchAll();
} catch (PDOException $e) {
    echo "Loi " . $e->getMessage();
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
    <div id="dssp">
        <?php
        foreach ($dssp as $sp) {
        ?>
        <div class="sp">
            <h2><?= $sp['ten'] ?></h2>
            <p><img src="images/upload/product/<?= $sp['hinh'] ?>" alt=""></p>
            <p><span class="gia"><?= number_format($sp['gia'], 0) ?> VND</span></p>
        </div>
        <?php
        }

        ?>
    </div>
</body>

</html>