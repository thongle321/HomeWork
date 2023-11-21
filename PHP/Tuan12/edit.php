<?php
$host = "localhost";
$dbname = "qlsp";
$username = "root";
$password = "";
try {
    $conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $id = $_GET['id'] ?? 0;
    $sql = "SELECT * FROM san_pham WHERE id = :id";
    $stmt = $conn->prepare($sql);
    $stmt->bindValue(":id", $id);
    $stmt->execute();
    $dssp = $stmt->fetch(PDO::FETCH_ASSOC);
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
            $sql = "UPDATE san_pham SET ten = :ten, loai = :loai, gia = :gia, mo_ta = :mota WHERE id = :id";
            $stmt = $conn->prepare($sql);
            $stmt->bindValue(":ten", $ten);
            $stmt->bindValue(":loai", $loai);
            $stmt->bindValue(":gia", $gia);
            $stmt->bindValue(":mota", $mota);
            $stmt->bindValue(":id", $id);
            $stmt->execute();
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
    <?php
    if ($dssp) {
    ?>
    <h1>Sửa sản phẩm</h1>
    <form action="" method="post">
        <label for="ten">Tên sản phẩm: </label>
        <input type="text" name="ten" required maxlength="255" value="<?= $dssp['ten'] ?>"><br>
        <br>
        <label for="loai">Loại sản phẩm: </label>
        <select name="loai" required>
            <?php
                foreach ($dslsp as $loai) {
                ?>
            <option value="<?= $loai['id']; ?>" <?= $loai['id'] == $dssp['loai'] ? 'selected' : '' ?>>
                <?= $loai['ten_loai']; ?></option>
            <?php
                }
                ?>
        </select>
        <br>
        <br>
        <label for="gia">Giá: </label>
        <input type="number" name="gia" required min="1" value="<?= $dssp['gia'] ?>"> <br>
        <br>
        <label for=" mota">Mô tả: </label> <br>
        <textarea name="mota" id="" cols="30" rows="4" required><?= $dssp['mo_ta'] ?></textarea> <br>
        <input type="submit" value="Cập nhật">
    </form>
    <?php
    } else {
        echo "Không tìm thấy id sản phẩm";
    }
    ?>
    <?php
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        if ($id > 0) {
            echo "Cập nhật thành công";
        } else {
            echo "Cập nhật thất bại";
        }
    }
    ?>

</body>

</html>