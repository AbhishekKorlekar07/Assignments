
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
		//Here we are fetching the value from the request body and storing it into an variable horseName
		$horseName =  $data["value"];
		//creating query object using PDO
		$getAllHorseRecordsQuery = $conn->prepare("select race.name, runsin.tm, runsin.finish from race, runsin where runsin.rid = race.race_id and runsin.hid = (select horse_id from horse where name = :horsename)");
		//making use of the prepared statement and replacing the horsename variable in the line below
		$getAllHorseRecordsQuery->execute(array(':horsename'=>$horseName));
		//here fetchAll is used to fetch all the rows in an array
		$horseRecords = $getAllHorseRecordsQuery->fetchAll();
		echo "<h3>All the race names, position it finished and time it took related to horse: ".$horseName;
		echo "</h3>";
		echo "<table border='1' cellpadding='10'>";
		echo "<tr>";
		echo "<th>Race Name</th>";
		echo "<th>Finish</th>";
		echo "<th>Time</th>";
		echo "</tr>";
		//iterating through the array fetched and displaying it row by row i.e here we are displaying the name, position and time it took.
		foreach($horseRecords as $rowValue){
			echo "<tr>";

			echo "<td>";
			print ($rowValue['name']);
			echo "</td>";


			echo "<td>";
			print ($rowValue['finish']);
			echo "</td>";

			echo "<td>";
			print ($rowValue['tm']);
			echo "</td>";

			echo "</tr>";	
		}
		echo "</table>";
	?>
</body>
</html>
