<?php

	$myfile = "verion.txt";
	$lines  = file($myfile);
	for ($x = 0; $x < 4; $x++) {
		echo $lines[$x];
		
	}
		
	
?>