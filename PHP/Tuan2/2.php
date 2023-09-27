<?php
// Khai báo mảng chứa các giá trị
$a = [
    "Tokyo",
    "Mexico City",
    "New York City",
    "Mumbai",
    "Seoul",
    "Shanghai",
    "Lagos",
    "Buenos Aires",
    "Cairo",
    "London"
];
sort($a);
for ($i = 0; $i < count($a); $i++) {
	 if($i == 0)
	 {
	 	echo $a[$i];
	 }
	 else
	 {
	 	echo ", " . $a[$i];
	 }
}
?>
<ul>
	<?php
	foreach($a as $value)
	{
		echo "<li>$value</li>";
	}
	?>
</ul>
<?php
$b = ["Los Angeles", "Calcutta", "Osaka", "Beijing"];
$a = array_merge($a,$b);
sort($a);
echo "Các giá trị trong mảng sau khi thêm và sắp xếp lại: ";
?>
<ul>
	<?php
	foreach($a as $value)
	{
		echo "<li>$value</li>";
	}
	?>
</ul>
<?php
?>