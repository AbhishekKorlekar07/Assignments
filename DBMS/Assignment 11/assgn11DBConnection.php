<!--
Name: Abhishek Jagannath Korlekar
Course: CSCI 566
Assignment No: 11
Due Date: 11/27/17
-->

<?php
	//defining variables and values that we would use to establish the connection.
	$servername = "courses";
	$username = "z1831187";
	$password = "1991Sep07";

	//execption handling while establishing connection.
	try{
		//using PDO to connect to database with the values provided in the previous step.
		$conn = new PDO("mysql:host=$servername; dbname=z1831187", $username, $password);
		$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	}catch(PDOException $e){
		//printing the error message in the case when exception occurs.
		echo "Connnection failed: ".$e->getMessage();
	}
?>

