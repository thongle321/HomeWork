<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php $nnlt = ["C++", "PHP"]; ?>
    <form action="" method="post">
        <h1>Nhập thông tin sinh viên</h1> <br>
        <label for="mssv">MSSV: </label>
        <input type="text" id="mssv" name="mssv"> <br>
        <br />
        <label for="hoten">Họ tên: </label>
        <input type="text" name="hoten" id="hoten" maxlength="22"> <br>
        <br />
        Giới tính:
        <label for="Nam">Nam</label>
        <input type="radio" name="gioitinh" id="gioitinh" value="Nam">
        <label for="Nu">Nữ</label>
        <input type="radio" name="gioitinh" id="gioitinh" value="Nu">
        <br />
        <br />
        Ngôn ngữ lập trình:
        <label for="cpp">C++</label>
        <input type="checkbox" name="nnlt[]" id="cpp" value="cpp">
        <label for="php">PHP</label>
        <input type="checkbox" name="nnlt[]" id="php" value="php">
        <br />
        <br />
        Thành phố:
        <select name="thanhpho" id="thanhpho">
            <option value="Hà Nội">Hà Nội</option>
            <option value="Thành Phố HCM">Thành Phố HCM</option>
        </select>
        <br />
        <label for="tinnhan">Tin nhắn</label>
        <br>
        <textarea name="tinnhan" id="tinnhan" cols="30" rows="10"></textarea> <br>
        <button name="submit" value="submit">Gửi</button>
    </form>
    <?php
    if (isset($_POST['submit'])) {
    
    }
    ?>

</body>

</html>