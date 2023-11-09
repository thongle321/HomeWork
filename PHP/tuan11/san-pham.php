<?php
    require_once($_SERVER['DOCUMENT_ROOT'].'\tuan11\lib\DB.php');

    $id = $_GET['id']??0;
    //Tự sửa câu SQL lại theo cấu trúc bảng
    $sql = 'SELECT `id`, `ten`, `loai`, `gia`, `hinh`, `mo_ta` FROM `san_pham` WHERE `Id` = :id';
    $dssp=DB::read($sql,[':id'=>$id]);
  
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Chi tiết sản phẩm</title>
</head>
<body>
    <?php
        if(count($dssp)==0) {echo '<p>Không tìm thấy</p>';}
        else{
            $sp=$dssp[0];
    ?>
        <h1><?=$sp['ten']?></h1>
        <p><img src="images/upload//product/<?=$sp['hinh']?>" alt=""></p>
        <p><span class="gia"><?=number_format($sp['gia'],0)?> VNĐ</span></p>
        <div><?=$sp['mo_ta']?></div>
    <?php
        }
    ?>
</body>
</html>