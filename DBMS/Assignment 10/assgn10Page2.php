
<!--
Name: Abhishek Jagannath Korlekar
Course: CSCI 566
Assignment No: 10
Due Date: 11/20/17
-->


<!DOCTYPE html>
<html>
	<head>
		<script>
			function getAllRaces(distanceVal){

				//clearing all the data in the div tag once the user selects value from dropdown list whose value is empty string
				if(distanceVal == "select"){
					document.getElementById("displayRacesTable").innerHTML = "";
				}else{

					//creating an XMLHttp request
					var xmlhttp = new XMLHttpRequest();
					//creating a function that would be execute when server responds with the data.
					xmlhttp.onreadystatechange = function(){
						if(xmlhttp.readyState == 3){
							document.getElementById("displayRacesTable").innerHTML = "Fetching Data.....";
						}
						//checking the response status which is 200 and its ready state is 4 
						else if(xmlhttp.readyState == 4 && xmlhttp.status == 200){
							//here populating the div tag with the response obtained from the ajax call
							document.getElementById("displayRacesTable").innerHTML = xmlhttp.responseText;
						//check if the state is a ready state and status not equal to 200, then prints the error message
						}else if(xmlhttp.readyState == 4 && xmlhttp.status != 200){
							document.getElementById("displayRacesTable").innerHTML = "Some Error has occurred. Please check the Database Logs";
						} 
					};
					//here making the call using POST request and passing the distance in the POST request body
					xmlhttp.open("POST","getAllRaceRecords.php");
					//setting header content type as application/json
					xmlhttp.setRequestHeader("Content-type","application/json");	
					//send the json data
					xmlhttp.send(JSON.stringify({"value" : distanceVal}));
				}
			}
		</script>
	</head>
	<body>
		<pre>
		<?php 
	                include "assgn10DBConnection.php"; //including the Db connection PHP file to establish connection with the database.
		?>
		<?php
			echo "<h1>Question 3: Allow user to choose(from dropdown) distance & then list all races with that distance</h1>";
			echo "<h2>Ans: </h2>";

			//creating query to get all the race records so that all the distances would be populated in the drop down menu
			$getDistanceListQuery = $conn->prepare("select distinct distance from race");
			$getDistanceListQuery->execute();

			//fetchall to return an array containing all result of rows ie. we would get all the distances in an array
			$distanceList = $getDistanceListQuery->fetchAll();
			echo "<form>";
			echo "<h3>Choose Distance to display races associated with it</h3>";
			//creating an onchange event when user chooses different distance and calling function getAllRaces to get all the race names related
			//to the distance .
			echo "<select onchange='getAllRaces(this.value)'>";
				echo "<option value='select'>Select distance</option>";
				//iterating through the distanceList array and displaying all the distances in the dropdown
				foreach($distanceList as $rowValue){
					echo "<option>".$rowValue['distance']."</option>";
				}	
			echo "</select>";	
			echo "</form>";

			//this div tag is used to populate data into it once we recieve data from the ajax call.	
			echo "<div id='displayRacesTable'></div>";
		?>
		</pre>
	</body>
</html>
