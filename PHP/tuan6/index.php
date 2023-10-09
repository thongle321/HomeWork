<?php
// biến chứa các thông báo lỗi
$errors = [];
// kiểm tra dữ liệu form hợp lệ không
$isValid = true;
// đường dẫn hình để hiện lên lại sau khi upload
$imgPath = [];

// đọc dữ liệu từ form
$mssv = $_POST['mssv'] ?? '';
$hoten = $_POST['hoten'] ?? '';
// kiểm tra dữ liệu ở server
if (isset($_POST['btn'])) {
    // kiểm tra MSSV
    if (trim($mssv) == '') {
        $errors['mssv'] = 'Mã số sinh viên không được bỏ trống';
        $isValid = false;
    } elseif (!preg_match('/^\d{10}$/', $mssv)) {
        $errors['mssv'] = 'Mã số sinh viên phải có 10 chữ số';
        $isValid = false;
    }
    // kiểm tra họ tên                
    elseif (trim($hoten) == '') {
        $errors['hoten'] = 'Họ tên không được bỏ trống';
        $isValid = false;
    }
    // tương tự kiểm tra các trường input khác
    // ...
    // kiểm tra upload hình
    elseif (!$_FILES['hinh']['tmp_name'][0]) {
        $errors['hinh'] = 'Chưa chọn hình';
        $isValid = false;
    } else {
        // kiểm tra lỗi cho từng file hình
        foreach ($_FILES['hinh']['error'] as $key => $err) {
            if ($err != 0) {
                $errors['hinh'] = 'Lỗi upload file';
                $isValid = false;
            }
        }
    }

    // nếu dữ liệu hợp lệ thì lưu thông tin
    if ($isValid) {
        //lưu thông tin vào CSDL (sẽ học trong bài sau)
        // ...
        //sau khi lưu CSDL thì lưu file hình
        foreach ($_FILES['hinh']['tmp_name'] as $key => $tmp_name) {
            // nên dùng đường dẫn riêng cho từng đối tượng (sinh viên/nhân viên/tài khoản/sản phẩm/bài viết/...)
            // để tránh bị trùng tên tập tin
            /*
                LƯU Ý: nếu file php này để trong htdocs thì nên để đường dẫn bắt đầu bằng dấu '/'                
            */
            $path = "images/upload/{$mssv}";
            // kiểm tra có đúng tập tin là do người dùng upload lên không
            if (is_uploaded_file($tmp_name)) {
                // nếu thư mục chưa tồn tại
                if (!is_dir($path)) {
                    // tạo thư mục
                    mkdir($path, 0777, true);
                }
                // lưu tập tin
                move_uploaded_file($tmp_name, "{$path}/ava{$key}.png");
                $imgPath[] = "{$path}/ava{$key}.png";
            }
        }
    }
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <!-- muốn upload tập tin thì form phải có method="post" và enctype="multipart/form-data" -->
    <form action="" method="post" enctype="multipart/form-data">
        <!-- kiểm tra dữ liệu nhập ở client: required, pattern, min, max, minlength, maxlength, ... (nên xóa phần kiểm tra dữ liệu ở client khi test chức năng kiểm tra ở server) -->
        <!-- lưu ý về pattern: 
            - thuộc tính pattern của thẻ input sẽ match toàn bộ nội dung chuỗi (tương tự như khi có ^ và $) 
            - nên dùng kèm với thuộc tính title để hiện thông báo 
        -->
        MSSV: <input type="text" name="mssv" required pattern="\d{10}" title="Mã số sinh viên phải có 10 chữ số" value="<?= $mssv ?>"><br>
        <?php
        if (isset($errors['mssv'])) {
            echo "<p class='error'>{$errors['mssv']}</p>";
        }
        ?>
        Họ tên: <input type="text" name="hoten" required value="<?= $hoten ?>"><br>
        <?php
        if (isset($errors['hoten'])) {
            echo "<p class='error'>{$errors['hoten']}</p>";
        }
        ?>
        Hình: <input type="file" name="hinh[]" multiple accept="image/*"><br>
        <?php
        if (isset($errors['hinh'])) {
            echo "<p class='error'>{$errors['hinh']}</p>";
        }
        ?>
        <button name="btn" value="submit">OK</button>
    </form>

    <?php
    // hiện cấu trúc mảng $_FILES để demo/debug
    echo "<pre>";var_dump($_FILES);echo "</pre>";
    if (isset($_POST['btn']) && $isValid) {
    ?>
        <h2>Dữ liệu: </h2>
        <p>MSSV: <?= $mssv ?></p>
        <p>Họ tên: <?= $hoten ?></p>
        <p>Hình:</p>
    <?php
        foreach ($imgPath as $key => $img) {
            echo "<img src='{$img}'>";
        }
    }
    ?>
</body>

</html>