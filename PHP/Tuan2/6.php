<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php
    // Hàm tính UCLN
    function UCLN($a, $b)
    {
        while ($b != 0) {
            $temp = $a % $b;
            $a = $b;
            $b = $temp;
        }
        return abs($a);
    }

    // Hàm tính BCNN
    function BCNN($a, $b)
    {
        return abs($a * $b) / UCLN($a, $b);
    }

    // Test hàm
    $a = 15;
    $b = 25;
    echo "BCNN của $a và $b là: " . BCNN($a, $b);
    ?>
</body>

</html>