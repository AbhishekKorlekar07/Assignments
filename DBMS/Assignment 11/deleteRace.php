
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
		//using json_decode to parse the json object
		$data = json_decode(file_get_contents('php://input'), true);
		//Here we are fetching the value from the request body and storing it into an variable raceName
		$raceID = $data["value"];
		try{
			//query to delete race from runsin table which would eliminate the foreign key constraint.
			$deleteRaceFromRunsinQuery = $conn->prepare("delete from runsin where rid = :raceId");
			$deleteRaceFromRunsinQuery->bindParam(":raceId",$raceID);
			$deleteRaceFromRunsinQuery->execute();
			//query to delete race from the database.
			$deleteRaceQuery = $conn->prepare("delete from race where race_id = :raceID");
			//binding all the paramters which we are using above using prepared statements.
			$deleteRaceQuery->bindParam(":raceID", $raceID);
			$deleteRaceQuery->execute();
			echo "<h2> Record Deleted Successfully</h2>";
			//showing link to return to previous page
			echo "<a href='assgn11Page3.php'>Return to previous page</a>";
		}catch(PDOException $e){
			//displaying error message in case exception occurs.
			echo "Message: " .$e->getMessage();
		}
		?>
	</body>
</html>
