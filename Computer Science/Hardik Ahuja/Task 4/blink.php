<html>
 <head>
 <meta name="viewport" content="width=device-width" />
 <title>LED Control</title>
 </head>
         <body>
         LED Control:
         <form method="get" action="blink.php">
Time :                  <input type="Text"  name="Time">
                 <input type="submit" value="ON" name="off">
         </form>
         <?php
         $setmode17 = shell_exec("/usr/local/bin/gpio -g mode 17 out");
        $tt = $_GET["Time"];
	if(isset($_GET['off'])){
		 for($i = 0;$i < $tt ; $i++){
                 $gpio_off = shell_exec("/usr/local/bin/gpio -g write 17 0");
                 sleep(1);
		 $gpio_on = shell_exec("/usr/local/bin/gpio -g write 17 1");
		 sleep(1);
        	 }
	}
	$gpio_off = shell_exec("/usr/local/bin/gpio -g write 17 0");
 
//      $lsls = shell_exec("ls -al");
//      echo $lsls;
         ?>
         </body>
 </html>

