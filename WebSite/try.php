<?php
	if(isset($_GET["Page"]))
	{
		if($_GET["Page"] == 1)
		{
			$myfile = "App.txt";
		    $lines  = file($myfile);
		    for ($x = ($_GET["Page"] * 64); $x < ($_GET["Page"] *64 + 64); $x++) {
		 	  echo $lines[$x];
	     	}
		}
	}
?>