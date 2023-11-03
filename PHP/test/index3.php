<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <form action="" method="post">
        <label for="ten">Tên:</label>
        <input type="text" name="ten" id="ten">
        <label for="namsinh">Năm sinh:</label>
        <input type="text" name="namsinh" id="namsinh">
        <button type="submit" name="btn">Gửi</button>
    </form>
    <?php
    if (isset($_POST['btn'])) {
        $now = getdate();
        $year = $_POST['namsinh'];
        $age = $now['year'] - $year;
        echo "<p>Chào mừng bạn {$_POST['ten']}! </p>";
        echo "<p>Bạn có tuổi là $age .</p>";
    }
    ?>
</body>

</html>