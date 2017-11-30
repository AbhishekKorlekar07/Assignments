<!--
Name: Abhishek Jagannath Korlekar
Course: CSCI 566
Assignment No: 11
Due Date: 11/27/17
-->

<html>
	<head>
	</head>
	<body>
		<?php
			include "assgn11DBConnection.php"; //including the connection file to open connection with DB
		?>

		<?php
		//fetching the values from the form
		$raceName = $_POST["raceName"];
		$distance = $_POST["distance"];
		try{
			//query to insert race details in the database.
			$insertNewRaceQuery = $conn->prepare("insert into race (name,distance) values (:racename,:distance)");
			//binding all the paramters which we are using above using prepared statements.
			$insertNewRaceQuery->bindParam(":racename", $raceName);
			$insertNewRaceQuery->bindParam(":distance", $distance);
			$insertNewRaceQuery->execute();
			echo "<h2> New Record inserted Successfully</h2>";
			//showing link to return to previous page
			echo "<a href='assgn11Page2.php'>Return to previous page</a>";
		}catch(PDOException $e){
			//displaying error message in case exception occurs.
			echo "Message: " .$e->getMessage();
		}
		?>
	</body>
</html>

