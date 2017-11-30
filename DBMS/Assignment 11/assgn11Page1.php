<!--
Name: Abhishek Jagannath Korlekar
Course: CSCI 566
Assignment No: 11
Due Date: 11/27/17
-->


<!-- In this page we are adding  new horse details (including sire and dam) -->
<html>
	<head>
	</head>
	<body>
	<pre>
		<?php
		echo "<h1>Question 1: Add a new horse (including the sire and dam)</h1>";
		//Submitting form to insertNewHorseDetails.php page where all the values would be received.
		echo "<form action='./insertNewHorseDetails.php' method='POST'>";
		echo "<label>Horse Name:</label><span style='color:red'>*</span><br/>";
		echo "<input type='text' name='horseName' maxlength='25' required><br/>";
		echo "<label>Sire:</label><span style='color:red'>*</span><br/>";
		echo "<input type='text' name='sire' maxlength='25' required><br/>";
		echo "<label>Dam:</label><span style='color:red'>*</span><br/>";
		echo "<input type='text' name='dam' maxlength='25' required><br/><br/>";
		//submitting the form elements by the submit button below 
		echo "<input type='submit' value='Submit'>";
		echo "</form>";
		?>	
	</pre>
	</body>
</html>
