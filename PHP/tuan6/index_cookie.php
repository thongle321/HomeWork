<?php
if(!isset($_COOKIE['a']))
{
    setcookie('a', '123', time()+10*3600, '','');

}
if(isset($_GET['logout']))
{
    setcookie('a', '123', time()-10*3600, '','');
}
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
    var_dump($_COOKIE);
    ?>
</body>

</html>