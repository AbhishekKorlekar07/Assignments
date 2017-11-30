<!--
Name: Abhishek Jagannath Korlekar
Course: CSCI 566
Assignment No: 11
Due Date: 11/27/17
-->

<html>
	<head>
		<script>
			function getRecordsRelevantToRace(raceName){
				//Here the div element would display blank value.  
				if(raceName == "select"){
					document.getElementById("displayRacesRelevantToSelectedRace").innerHTML = "";
				}else{

					//creating an XMLHttp request
					var xmlhttp = new XMLHttpRequest();
					//creating a function that would be execute when server responds with the data.
					xmlhttp.onreadystatechange = function(){
						if(xmlhttp.readyState == 3){
							document.getElementById("displayRacesRelevantToSelectedRace").innerHTML = "Fetching Data.....";
						}
						//checking the response status which is 200 and its ready state is 4 
						else if(xmlhttp.readyState == 4 && xmlhttp.status == 200){
							//here populating the div tag with the response obtained from the ajax call
							document.getElementById("displayRacesRelevantToSelectedRace").innerHTML = xmlhttp.responseText;
						//check if the state is a ready state and status not equal to 200, then prints the error message
						}else if(xmlhttp.readyState == 4 && xmlhttp.status != 200){
							document.getElementById("displayRacesRelevantToSelectedRace").innerHTML = "Some Error has occurred. Please check the Database Logs";
						} 
					};
					//calling open function and passing the value to getRaceRecordsRelevantToSelectedRace.php file
					xmlhttp.open("POST","getRaceRecordsRelevantToSelectedRace.php");
					//setting header content type as application/json
					xmlhttp.setRequestHeader("Content-type","application/json");	
					//send the json data
					xmlhttp.send(JSON.stringify({"value" : raceName}));
				}
			}


			function deleteRace(raceid){
				//creating an XMLHttp request
				var xmlhttp = new XMLHttpRequest();
				//creating a function that would be execute when server responds with the data.
				xmlhttp.onreadystatechange = function(){
					//checking the response status which is 200 and its ready state is 4 
					if(xmlhttp.readyState == 4 && xmlhttp.status == 200){
						window.location = "deleteRace.php";			
					}
				};
				//calling open function and passing the value to deleteRace.php file
				xmlhttp.open("POST","deleteRace.php");
				//setting header content type as application/json
				xmlhttp.setRequestHeader("Content-type","application/json");	
				//send the json data
				xmlhttp.send(JSON.stringify({"value" : raceid}));
			}
		</script>
	</head>
	<body>
		<pre>
		<?php 
	                include "assgn11DBConnection.php"; //including the Db connection PHP file to establish connection with the database.
		?>
		<?php	
		echo "<h1>Question 3: Delete an existing race</h1>";
			
		echo "<h2>Ans: </h2>";
		//creating query to get all the race names so that all the race names would be populated in the drop down menu
		$getRacesListQuery = $conn->prepare("select distinct name from race");
		$getRacesListQuery->execute();
		//fetchall to return an array containing rows of raceNames ie. we would get all the race names in an array
		$racesList = $getRacesListQuery->fetchAll();
		echo "<form>";
		echo "<h3>Delete an existing race</h3>";
		echo "<select onchange='getRecordsRelevantToRace(this.value)'>";
			echo "<option value='select'>Select RaceName</option>";
			//iterating through the racesList array and displaying all the race names in the dropdown
			foreach($racesList as $rowValue){
				echo "<option>".$rowValue['name']."</option>";
			}	
		echo "</select>";	
		echo "</form>";

		//here all the races would be displayed which would be relevant to the race selected in the dropdown 
		echo "<div id='displayRacesRelevantToSelectedRace'></div>";
		?>
		</pre>
	</body>
</html>
