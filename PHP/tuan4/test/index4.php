<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="" method="post">
        <input type="text" name="so1" id="so1" placeholder = "Số thứ 1">
        <label for="cong">+</label>
        <input type="radio" name="dau" value = "+">
        <label for="tru">-</label>
        <input type="radio" name="dau" value = "-">
        <label for="nhan">*</label>
        <input type="radio" name="dau" value = "*">
        <label for="chia">/</label>
        <input type="radio" name="dau" value = "/">
        <input type="text" name="so2" id="so2" placeholder = "Số thứ 2">
        <button type="submit" name = "btn">Tính</button>
    </form>
    <?php
    if(isset($_POST['btn']))
    {
        $so1 = $_POST['so1'];
        $so2 = $_POST['so2'];
        $tong = $so1 + $so2;
        $hieu = $so1 - $so2;
        $tich = $so1 * $so2;
        $thuong = $so1 / $so2;
        switch($_POST['dau'])
        {
            case '+': echo "$so1 + $so2 = $tong";break;
            case '-': echo "$so1 - $so2 = $hieu";break;
            case '*': echo "$so1 * $so2 = $tich";break;
            case '/': echo "$so1 / $so2 = $thuong";break;
        }

    }
    ?>
</body>
</html>