<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php
    // Hàm kiểm tra số nguyên tố
    function SNT($n)
    {
        if ($n < 2) {
            return false;
        }
        for ($i = 2; $i < $n; $i++) {
            if ($n % $i == 0) {
                return false;
            }
        }
        return true;
    }

    // Tính tổng các số nguyên tố từ 1 đến 9999
    $tong = 0;
    for ($i = 1; $i <= 9999; $i++) {
        if (SNT($i)) {
            $tong += $i;
        }
    }

    // In ra màn hình
    echo "Tổng các số nguyên tố từ 1 đến 9999 là: $tong";
    ?>

</body>

</html>