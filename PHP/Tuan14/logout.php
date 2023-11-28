<?php
session_start();
session_destroy();
setcookie("usernane", '', -0);
header("Location: index.php");
exit;
