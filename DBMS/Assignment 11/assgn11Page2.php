<!--
Name: Abhishek Jagannath Korlekar
Course: CSCI 566
Assignment No: 11
Due Date: 11/27/17
-->

<!-- In this page we are adding  new race details  -->
<html>
	<head>
	</head>
	<body>
	<pre>
		<?php
		echo "<h1>Question 2: Add New race</h1>";
		//Submitting form to insertNewRaceDetails.php page where all the values would be received.
		echo "<form action='./insertNewRaceDetails.php' method='POST'>";
		echo "<label>Race Name:</label><span style='color:red'>*</span><br/>";
		echo "<input type='text' name='raceName' maxlength='30' required><br/>";
		echo "<label>Distance:</label><span style='color:red'>*</span><br/>";
		echo "<input type='text' name='distance' maxlength='10' required><br/><br/>";
		//submitting the form elements by the submit button below 
		echo "<input type='submit' value='Submit'>";
		echo "</form>";
		?>	
	</pre>
	</body>
</html>
