<?php
    require_once($_SERVER['DOCUMENT_ROOT'].'\tuan11\lib\DB.php');
    //Tự sửa câu SQL lại theo cấu trúc bảng
    $sql = 'SELECT `id`, `ten`, `loai`, `gia`, `hinh`, `mo_ta` FROM `san_pham`';
    $sql1 = "INSERT INTO san_pham (id, ten, loai, gia, hinh, mo_ta) VALUES ('5', 'San pham 5', '1', '50000', '05.png', 'Mo ta san pham 5')";

    $dssp = DB::read($sql);
    $addsp = DB::read($sql1);    
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Trang chủ</title>
</head>

<body>
    <!-- Tự thêm các thẻ HTML khác để có giao hiện hoàn chỉnh -->
    <div id="dssp">
        <?php
            foreach ($dssp as $sp) {
        ?>
                <div class="sp">
                    <h2><a href="/php_22d/san-pham.php?id=<?=$sp['id']?>"><?=$sp['ten']?></a></h2>
                    <p><img src="images/upload/product/<?=$sp['hinh']?>" alt=""></p>
                    <p><span class="gia"><?=number_format($sp['gia'],0)?> VNĐ</span></p>
                </div>
        <?php
            }
        ?>
    </div>
</body>

</html>