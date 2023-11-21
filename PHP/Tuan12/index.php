<?php
$host = "localhost";
$dbname = "qlsp";
$username = "root";
$password = "";
try {
    $conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = "SELECT * FROM  san_pham";
    $dssp = $conn->prepare($sql);
    $dssp->execute();
    $dssp->setFetchMode(PDO::FETCH_ASSOC);
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
    <br>
    <?php
    echo "<a href='add.php'>Thêm</a>";
    echo "<br>";
    foreach ($dssp->fetchAll() as $dong) {
    ?>
        <a href="details.php?id=<?= $dong['id'] ?>"><?= $dong['ten'] . ": " ?></a>
        <p>giá: <?= $dong['gia'] ?></p>
    <?php
    }
    ?>
</body>

</html>