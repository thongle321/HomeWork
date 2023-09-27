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
    if (!isset($_FILES['hinh'])) {
        $error['hinh'] = "chua chon hinh";
        $isvalied = false;
    } else {
        foreach ($_FILES['hinh']['error'] as $key => $img) {
            if ($err != 0) {
                $error['hinh'] = "Loi upload file";
                $isvalied = false;
            }
        }
        if ($isvalied) {
            foreach ($_FILES['hinh']['tmp_name'] as $key => $tmp_name) {
                $path = "images\upload\{$mssv}";
                if (is_uploaded_file($tmp_name)) {
                    if (!is_dir($path)) {
                        mkdir($path, 0777, true);
                    }
                    move_uploaded_file($tmp_name, "{$path}\\ava{key}.png");
                    $imgPath[] = "{$path}/ava{$key}.png";
                }
            }
        }
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
    <form action="" method="post" enctype="multipart/form-data">
        MSSV: <input type="text" name="mssv" pattern="\d{10}" title="Ma so sinh vien phai co 10 chu so" value="<?= $mssv ?>"><br>
        <?php
        if (isset($error['mssv'])) {
            echo "<p class = 'error'>{$error['mssv']}</p>";
        }
        ?>
        Hinh: <input type="file" name="hinh[]" multiple accept="image/"><br>
        <button name="btn" value="submit">OK</button>
    </form>
    <?php
    echo "<pre>";
    var_dump($_FILES);
    echo "</pre>";
    if (isset($_POST['btn']) && $isvalied) {
        echo "<p> Du lieu nhap: </p>";
        echo "<p> MSSV: </p> 1mssv ";
        echo "<p> hinh:";
        foreach ($imgPath as $key => $img) {
            echo "<img src= '{$img}' > ";
        }
        echo "</p>";
    }
    ?>
</body>

</html>