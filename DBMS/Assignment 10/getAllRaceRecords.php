
<!--
Name: Abhishek Jagannath Korlekar
Course: CSCI 566
Assignment No: 10
Due Date: 11/20/17
-->

<!DOCTYPE html>
<html>
<body>
	<?php
                include "assgn10DBConnection.php"; //including the Db connection PHP file to establish connection with the database.
	?>
	<?php
		//using json_decode to parse the json object
		$data = json_decode(file_get_contents('php://input'), true);
		//Here we are fetching the value from the request body and storing it into an variable distanceValue
		$distanceValue =  $data["value"];
		//creating query object using PDO
		$getAllRacesFromDistanceQuery = $conn->prepare("select * from race where distance = '".$distanceValue."'");
		$getAllRacesFromDistanceQuery->execute();
		//here fetchAll is used to fetch all the rows in an array
		$raceRecords = $getAllRacesFromDistanceQuery->fetchAll();
		echo "<h3>All the race names corresponding to the distance: ".$distanceValue;
		echo "</h3>";
		echo "<table border='1' cellpadding='10'>";
		echo "<tr>";
		echo "<th>Race Name</th>";
		echo "</tr>";
		//iterating through the array fetched and displaying it row by row i.e here we are displaying all the race names related to the distanceValue
		foreach($raceRecords as $rowValue){
			echo "<tr>";
			echo "<td>";
			print ($rowValue['name']);
			echo "</td>";
			echo "</tr>";	
		}
		echo "</table>";
	?>
</body>
</html>
