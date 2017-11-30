
<!--
Name: Abhishek Jagannath Korlekar
Course: CSCI 566
Assignment No: 11
Due Date: 11/27/17
-->

<!DOCTYPE html>
<html>
<head></head>
<body>
	<?php
                include "assgn11DBConnection.php"; //including the Db connection PHP file to establish connection with the database.
	?>
	<?php
		//using json_decode to parse the json object
		$data = json_decode(file_get_contents('php://input'), true);
		//Here we are fetching the value from the request body and storing it into an variable raceName
		$raceName =  $data["value"];
		//creating query object using PDO
		$getAllRacesFromRaceNameQuery = $conn->prepare("select * from race where name = :raceName");
		$getAllRacesFromRaceNameQuery->execute(array(':raceName'=>$raceName));
		//here fetchAll is used to fetch all the rows in an array
		$raceRecords = $getAllRacesFromRaceNameQuery->fetchAll();
		echo "<h3>All the race(s) whose Race Name is : ".$raceName;
		echo "</h3>";
		?>

		<form>
		<table border="1" cellpadding="10">
		<tr>
		<th>Race ID</th>
		<th>Race Name</th>
		<th>Distance</th>
		<th>Action</th>
		<tr>
		<!-- Iterating through the array and displaying all the values -->
		<?php foreach($raceRecords as $rowValue){ ?>
		<tr>
		<td><input type="text" style="border:none; border-color:transparent;" id="raceID" name="raceID" value="<?php echo $rowValue['race_id']?>" readonly></td>
		<td><input type="text" style="border:none; border-color:transparent;" id="raceName" name="raceName" value="<?php echo $rowValue['name']?>" readonly></td>
		<td><input type="text" style="border:none; border-color:transparent;" id="raceDistance" name="raceDistance" value="<?php echo $rowValue['distance']?>" readonly></td>
		<!-- Here we passing the race id to the deleteRace function which would delete the particular record -->
		<td><button type="button" onclick="deleteRace(<?php echo $rowValue['race_id']?>)">Delete</button></td>
		</tr>
		<?php }?>
		</table>
		</form>
</body>
</html>
