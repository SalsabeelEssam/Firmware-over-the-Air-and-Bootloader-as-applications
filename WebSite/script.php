<?php 
if(isset($_GET['status']))
{
	/* Open the File */
	$myFile = fopen("status.txt","w");
	if($_GET['status'] == 'ON')
	{
		fwrite($myFile,'1');
		header("Location:on.html");
	}
	elseif($_GET['status'] == 'OFF')
	{
		fwrite($myFile,'0');
		header("Location:off.html");
	}
	/* Close File */
	fclose($myFile);
}

?>