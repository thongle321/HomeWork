<?php
$host = "localhost";
$dbname = "qlsv";
$username = "root";
$password = "";
$id = isset($_POST['id'])? $_POST['id']: "";
$mssv = isset($_POST['mssv'])? $_POST['mssv']: "";
$hoten = isset($_POST['hoten'])? $_POST['hoten']: "";
$diem = isset($_POST['diem'])? $_POST['diem']: "";
$sql = "INSERT INTO sinh_vien VALUES('$id', '$mssv', '$hoten', '$diem')";
try
 { 
    $conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $conn->exec($sql);
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
    <form action="" method="post">
    MSSV: <input type="text" name = "mssv" maxlength = "10"> <br>
    <br>
    HoTen: <input type="text" name = "hoten" > <br>
    <br>
    Diem: <input type="number" name = "diem"> <br>
    <button type="submit">submit</button>
    </form>
</body>
</html>