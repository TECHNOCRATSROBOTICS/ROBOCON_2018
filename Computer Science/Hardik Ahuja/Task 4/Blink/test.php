<html>
 <head>
 <meta name="viewport" content="width=device-width" />
 <title>LED Blink</title>
 </head>
         <body>
         LED Blink:
         <form method="get" action="test.php">
                Time :  <input type="text" name="t">
                 <input type="submit" value="Submit" name="on">
         </form>
         <?php
         if(isset($_GET['on'])){
		 $ti = $_GET["t"];
		 //echo $ti;
		 for ($i = 0 ; $i < $ti ; $i++){
		 	$g = shell_exec("sudo python3 led1.3.py");
		 }
		 echo $g;
         }
         ?>
         </body>
 </html>
