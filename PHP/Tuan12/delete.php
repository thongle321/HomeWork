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
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $sql = "DELETE FROM san_pham WHERE id = :id";
        $stmt = $conn->prepare($sql);
        $stmt->bindValue(":id", $id);
        $stmt->execute();
    }
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
        echo "<h1>Xoá sản phẩm</h1>";
        echo "Tên sản phẩm:" . $dssp['ten'] . "<br>";
        echo "Loại:" . $dssp['loai'] . "<br>";
        echo "Giá:" . $dssp['gia'] . "<br>";
        echo "Mô tả: " . $dssp['mo_ta'] . "<br>";
        echo "Bạn có chắc muốn xóa sản phẩm này?";

    ?>
        <form action="" method="post">
            <input type="submit" value="Đồng ý">
            <a href="details.php?id=<?= $dssp['id'] ?>"><input type="button" value="Quay lại"></a>
        </form>

        <?php
        ?>
        <br>
    <?php
    } else {
        echo "Không tìm thấy sản phẩm để xoá";
    }
    ?>

    <?php
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        if ($id > 0) {
            echo "Xóa thành công";
        } else {
            echo "Xoá thất bại";
        }
    }
    ?>
</body>

</html>