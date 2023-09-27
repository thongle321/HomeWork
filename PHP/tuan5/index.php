<?php
$error = [];
$mssv = $_POST['mssv'] ?? "";
$isvalied = true;
if (isset($_POST['btn'])) {
    if (!$mssv || trim($mssv) == '') {
        $error['mssv'] = 'Ma so sinh vien khong duoc de trong';
        $isvalied = false;
    } elseif (!preg_match('/^\d{10}$/', $mssv)) {
        $error['mssv'] = 'Ma so sinh vien phai co 10 chu so';
        $isvalied = false;
    }
}
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <form action="" method="post" enctype="multipart/form-data"> <br>
        MSSV: <input type="text" name="mssv" pattern="\d{10}" title="Ma so sinh vien phai co 10 chu so"
            value="<?= $mssv ?>">
        <?php
        if (isset($error['mssv'])) {
            echo "<p class = 'error'>{$error['mssv']}</p>";
        }
        ?>
        <button name="btn" value="submit">OK</button>
    </form>
    <?php
    if (isset($_POST['btn']) && $isvalied) {
        echo "<p> Du lieu nhap: </p>";
        echo "<p> MSSV: </p> 1mssv ";
    }
    ?>
</body>

</html>