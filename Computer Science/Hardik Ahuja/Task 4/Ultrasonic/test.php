<html>
 <head>
 <meta name="viewport" content="width=device-width" />
 <title>Ultrasonic</title>
 </head>
         <body>
         Ultrasonic:
         <form method="get" action="test.php">
               <input type="submit" value="Submit" name="on">
         </form>
         <?php
         if(isset($_GET['on'])){
	  	 $g = shell_exec("sudo python3 ultrasonic1.2.py");
		 echo $g;
		 //echo $g<20;
		 //if ($g < 20){
//			 $a = shell_exec("sudo play a.mp3");
//		 }
         }
         ?>
         </body>
 </html>
