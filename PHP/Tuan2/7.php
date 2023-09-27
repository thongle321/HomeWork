<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php
    // Hàm tính giai thừa
    function GiaiThua($n)
    {
        $kq = 1;
        for ($i = 1; $i <= $n; $i++) {
            $kq *= $i;
        }
        return $kq;
    }

    // Hàm tính tổ hợp chập k của n
    function ToHop($n, $k)
    {
        return GiaiThua($n) / (GiaiThua($n - $k) * GiaiThua($k));
    }

    // Test hàm
    $n = 5;
    $k = 3;
    echo "Tổ hợp chập $k của $n là: " . ToHop($n, $k);
    ?>

</body>

</html>