<?php
session_start();
session_destroy();
setcookie("usernane", '', -3600 * 24 * 7);
header("Location: index.php");
exit;
