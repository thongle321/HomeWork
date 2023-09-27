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
        <input type="radio" name="gender" id="gender" value="Nam">
        <label for="Nu">Nữ</label>
        <input type="radio" name="gender" id="gender" value="Nu">
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
        <br>
        <button name="submit" value="submit">Gửi</button>
        <br>
    </form>
    <?php
    if (isset($_POST['submit'])) {
    ?>
    <h1>Thong tin da nhan </h1>
    <p>MSSV:<?= $_POST['mssv'] ?></p>
    <p>Họ tên:<?= $_POST['hoten'] ?></p>
    <p>Giới tính:
        <?php
            if (isset($_POST['gender'])) {
                if ($_POST['gender'] == "Nam") {
                    if ($_POST['gender'] == "Nam") {
                        echo "Nam";
                    } elseif ($_POST['gender'] == "Nu") {
                        echo "Nữ";
                    }
                }
            }
            ?>
    </p>
    <p>Ngôn ngữ lập trình:
        <?php
            if (isset($_POST["nnlt"])) {
                foreach ($_POST["nnlt"] as $value) {
                    switch ($value) {
                        case 'cpp';
                            echo "C++";
                            break;
                        case 'php';
                            echo "PHP";
                            break;
                    }
                    //echo $value, ",";
                }
            }
            ?>
    </p>
    <p>Thành phố:
        <?= $_POST['thanhpho'] ?>
    </p>
    <?php
    }
    ?>

</body>

</html>