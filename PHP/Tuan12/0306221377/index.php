<?php
$host = "localhost";
$dbname = "qlsv";
$username = "root";
$password = "";
try
 { 
    $conn =new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} 
catch(PDOException $e) {
    echo"Kết nối CSDL thất bại: ". $e->getMessage();
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
    try
    {
    $sql = "SELECT * FROM  sinh_vien" ;
    $slnv = $conn->prepare($sql);
    $slnv->execute();
    $slnv->setFetchMode(PDO::FETCH_ASSOC);
    foreach($slnv->fetchALL() as $dong)
    {
        echo "id: " . $dong["id"] . " mssv: " . $dong["mssv"] . 
        " hoten: " . $dong["hoten"] . " diem: " . $dong["diem"] . "<br>";

    }
    }
    catch(PDOException $e)
    {
        echo "Khong ket noi thanh cong: " . $e->getMessage();
    }
    ?>
</body>
</html>