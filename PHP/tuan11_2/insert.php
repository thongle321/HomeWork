<?php
$mssv = "";
$username = "";
$ngaysinh = "";
$gioitinh = "";
$lop = "";
$dcc = "";
$dtbkt = "";
$diemthi = "";
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if(isset($_POST["mssv"])) { $title = $_POST['mssv']; }
    if(isset($_POST["username"])) { $username = $_POST['username']; }
    if(isset($_POST["ngaysinh"])) { $ngaysinh = $_POST['ngaysinh']; }
    if(isset($_POST["gioitinh"])) { $gioitinh = $_POST['gioitinh']; }
    if(isset($_POST["lop"])) { $lop = $_POST['lop']; }
    if(isset($_POST["dcc"])) { $dcc = $_POST['dcc']; }
    if(isset($_POST["dtbkt"])) { $dtbkt = $_POST['dtbkt']; }
    if(isset($_POST["diemthi"])) { $diemthi = $_POST['diemthi']; }
}
    $sql = "INSERT INTO sinh_vien (mssv, ho_ten, loai, gia, hinh, mo_ta) VALUES ('5', 'San pham 5', '1', '50000', '05.png', 'Mo ta san pham 5')";

?>