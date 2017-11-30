<!--
Name: Abhishek Jagannath Korlekar
Course: CSCI 566
Assignment No: 10
Due Date: 11/20/17
-->

<!DOCTYPE html>
<html>
	<body>
	<pre>
	<?php
		include "assgn10DBConnection.php"; //including the Db connection PHP file to establish connection with the database.
	?>
	<?php
		echo "<h1> Question 1: Show all of the horse names along with their sires and dams ? </h1>";
		echo "<h2>Ans: </h2>";
		//creating query object to get all the horse records from the database
		$horsesList = "select * from horse";
		//creating a table to populate all the data in the table
		echo "<table border='1' cellpadding='10'>";

		echo "<tr>";
		echo "<th>Horse Name</th>";
		echo "<th>Sire</th>";
		echo "<th>Dam</th>";
		echo "</tr>";
		//making use of foreach loop to iterate all the records one by one and place it in a table row
		foreach($conn->query($horsesList) as $row){
			echo "<tr>";
			echo "<td>";
			print ($row['name']);
			echo "</td>";
			
			echo "<td>";
			print ($row['sire']);
			echo "</td>";

			echo "<td>";
			print ($row['dam']);
			echo "</td>";
			echo "</tr>";
		}
		echo "</table>";


		
		echo "<h1> Question 2: show all of the race names and distances ?</h1>";
		echo "<h2>Ans: </h2>";

		//creating query object to get all the race records from the database
		$raceList = "select * from race";

		//creating a table to populate all the data in the table
		echo "<table border='1' cellpadding='10'>";

		echo "<tr>";
		echo "<th>Race Name</th>";
		echo "<th>Distance</th>";
		echo "</tr>";
	
		//making use of foreach loop to iterate all the records one by one and place it in a table row
		foreach($conn->query($raceList) as $row){
			echo "<tr>";
			echo "<td>";
			print ($row['name']);
			echo "</td>";
			
			echo "<td>";
			print ($row['distance']);
			echo "</td>";
			echo "</tr>";
		}
		echo "</table>";
	?>
	</pre>
	</body>
</html>
