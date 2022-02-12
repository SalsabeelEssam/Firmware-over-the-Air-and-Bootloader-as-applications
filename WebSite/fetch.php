<?php
	if(isset($_GET["Page"]) and isset($_GET["Player"]))
	{
		if($_GET["Player"] == 1)
		{
			$myfile = "player1.txt";
		}
		elseif($_GET["Player"] == 2)
		{
			$myfile = "player2.txt";
		}
		elseif($_GET["Player"] == 3)
		{
			$myfile = "player3.txt";
		}
		elseif($_GET["Player"] == 4)
		{
			$myfile = "player4.txt";
		}
		$lines  = file($myfile);
		for ($x = ($_GET["Page"] * 64); $x < ($_GET["Page"] *64 + 64); $x++) {
			echo $lines[$x];
		}
		
	}
?>