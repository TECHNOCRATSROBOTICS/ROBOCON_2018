<html>
 <head>
 <meta name="viewport" content="width=device-width" />
 <title>LED Blink</title>
 </head>
         <body>
         Servo Control
         <form method="get" action="test.php">
                Angle :  <input type="text" name="t">
                 <input type="submit" value="Submit" name="on">
         </form>
         <?php
         if(isset($_GET['on'])){
		 $ti = $_GET["t"];
//		 echo $ti;
		//echo "sudo echo '$ti'>file";
		 $ti = "aa".$ti;
//		echo $ti;
		 $a = shell_exec("sudo mkdir $ti");
		// $h = shell_exec("python hello.py".$ti);
//		 $g = shell_exec("sudo python hello.py");
		 $h = shell_exec("sudo python list.py");
		 $j = shell_exec("sudo rmdir aa*");
//		 echo $g;
		 echo "done";
         }
         ?>
         </body>
 </html>
