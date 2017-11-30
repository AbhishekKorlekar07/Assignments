
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
		$horseName = $_POST["horseName"];
		$sire = $_POST["sire"];
		$dam = $_POST["dam"];
		try{
			//query to insert horse details in the database.
			$insertNewHorseQuery = $conn->prepare("insert into horse (name,sire, dam) values (:horsename,:sirename,:damname)");
			//binding all the paramters which we are using above using prepared statements.
			$insertNewHorseQuery->bindParam(":horsename", $horseName);
			$insertNewHorseQuery->bindParam(":sirename", $sire);
			$insertNewHorseQuery->bindParam(":damname", $dam);
			$insertNewHorseQuery->execute();
			echo "<h2> New Record inserted Successfully</h2>";
			//showing link to return to previous page
			echo "<a href='assgn11Page1.php'>Return to previous page</a>";
		}catch(PDOException $e){
			//displaying error message in case exception occurs.
			echo "Message: " .$e->getMessage();
		}
		?>
	</body>
</html>

