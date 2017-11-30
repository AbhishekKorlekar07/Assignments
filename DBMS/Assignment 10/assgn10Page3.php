
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
			function getAllHorseRecords(horseName){
				
				//clearing all the data in the div tag once the user selects value from dropdown list whose value is empty string
				if(horseName == "select"){
					document.getElementById("displayHorseRecordsTable").innerHTML = "";
				}else{
					//creating an XMLHttp request
					var xmlhttp = new XMLHttpRequest();
					//creating a function that would be execute when server responds with the data.
					xmlhttp.onreadystatechange = function(){
						if(xmlhttp.readyState == 3){
							document.getElementById("displayHorseRecordsTable").innerHTML = "Fetching Data.....";
						}
						//checking the response status which is 200 and its ready state  is 4
						else if(xmlhttp.readyState == 4 && xmlhttp.status == 200){
						//here populating the div tag with the response obtained from the ajax call
							document.getElementById("displayHorseRecordsTable").innerHTML = xmlhttp.responseText;
						//check if the state is a ready state and status not equal to 200, then prints the error message
						}else if(xmlhttp.readyState == 4 && xmlhttp.status != 200){
							document.getElementById("displayHorseRecordsTable").innerHTML = "Some Error has occurred. Please check the Database Logs";
						} 

					};
					//here making the call using POST request and passing the distance in the POST request body
					xmlhttp.open("POST","getAllHorseDetails.php");
					//setting header content type as application/json
					xmlhttp.setRequestHeader("Content-type","application/json");	
					//send the json data
					xmlhttp.send(JSON.stringify({"value" : horseName}));
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
			echo "<h1>Question 4: Choose horse name and show all race names, its position and time</h1>";
			echo "<h2>Ans: </h2>";
			//creating query to get all the horse records so that horse names would be populated in the drop down menu
			$getHorseListQuery = $conn->prepare("select * from horse");
			$getHorseListQuery->execute();
			//fetchall to return an array containing all result of rows ie. we would get list of all horse records in an array
			$horseList = $getHorseListQuery->fetchAll();
			echo "<form>";
			echo "<h3>Choose Horse name to display all of its race names, position and distance</h3>";
			//creating an onchange event when user chooses different horse name and calling function getAllHorseRecords to get all races, position and
			//time it finished on.
			echo "<select onchange='getAllHorseRecords(this.value)'>";
				echo "<option value='select'>Select Horse</option>";
				//iterating through the horseList array and displaying all the horse names in the dropdown
				foreach($horseList as $rowValue){
					echo "<option>".$rowValue['name']."</option>";
				}	
			echo "</select>";	
			echo "</form>";

			//this div tag is used to populate data into it once we recieve data from the ajax call.	
			echo "<div id='displayHorseRecordsTable'></div>";
		?>
		</pre>
	</body>
</html>
