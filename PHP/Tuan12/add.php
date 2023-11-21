<?php
$host = "localhost";
$dbname = "qlsp";
$username = "root";
$password = "";
$id = -1;
try {
    $conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = "SELECT * FROM  loai_san_pham";
    $stmt = $conn->prepare($sql);
    $stmt->execute();
    $dslsp = $stmt->fetchAll(PDO::FETCH_ASSOC);

    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $ten = trim($_POST['ten'] ?? '');
        $loai = $_POST['loai'] ?? '';
        $gia = trim($_POST['gia'] ?? '');
        $mota = trim($_POST['mota'] ?? '');
        if (!$ten) {
            echo "Tên Không được bỏ trống";
        }
        if (!$loai) {
            echo "Loại Không được bỏ trống";
        }
        if (!$gia) {
            echo "Giá Không được bỏ trống";
        }
        if (!$mota) {
            echo "Mô tả Không được bỏ trống";
        } else {
            $sql = "INSERT INTO san_pham (ten, loai, gia, mo_ta) VALUES (:ten, :loai, :gia, :mota)";
            $stmt = $conn->prepare($sql);
            $stmt->bindValue(":ten", $ten);
            $stmt->bindValue(":loai", $loai);
            $stmt->bindValue(":gia", $gia);
            $stmt->bindValue(":mota", $mota);
            $stmt->execute();
            $id = $conn->lastInsertId();
        }
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
    <form action="" method="post">
        <label for="ten">Tên sản phẩm: </label>
        <input type="text" name="ten" required maxlength="255"><br>
        <br>
        <label for=" loai">Loại sản phẩm: </label>
        <select name="loai" required>
            <?php
            foreach ($dslsp as $loai) {
            ?>
                <option value=" <?= $loai['id']; ?>"><?= $loai['ten_loai']; ?></option>
            <?php
            }
            ?>
        </select>
        <br>

        <br>
        <label for="gia">Giá: </label>
        <input type="number" name="gia" required min="1"> <br>
        <br>
        <label for="mota">Mô tả: </label> <br>
        <textarea name="mota" id="" cols="30" rows="4" required></textarea> <br>

        <input type="submit" value="them">

    </form>
    <?php
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        if ($id > 0) {
            echo "Thêm thành công";
        } else {
            echo "Thêm thất bại";
        }
    }
    ?>
</body>

</html>