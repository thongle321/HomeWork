<?php
session_start();
session_destroy();
setcookie("username", '', -3600 * 24 * 7);
header("Location: index.php");
exit;