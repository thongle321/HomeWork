<?php
session_start();
session_destroy();
setcookie('user', '', time()-3600*24*7);
header('Location: /0306221377_tuan6/index_login.php');