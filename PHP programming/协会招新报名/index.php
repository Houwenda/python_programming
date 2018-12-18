<?php
  if(!(isset($_POST['action'])&&isset($_POST['name'])&&isset($_POST['grade'])&&isset($_POST['email'])&&isset($_POST['phone'])&&isset($_POST['department']))){
    echo "How do you do?";
  }
  else{
    if(isset($_POST['action'])){
      $info = $_POST['name'].' '.$_POST['grade'].' '.$_POST['email'].' '.$_POST['phone'].' '.$_POST['department']."\r\n";
      $phone = htmlspecialchars_decode($_POST['phone'], ENT_QUOTES);
      //echo $info;
      if(!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)){
        echo '<script>alert("请输入正确邮箱地址");history.back();</script>';
      }
      else if(!preg_match("/^1[34578]{1}\d{9}$/",$phone)){
        echo '<script>alert("请输入正确号码");history.back();</script>';
      }
      else{
        $file = fopen("members.txt",'r');
        while (! feof($file)) {
          $line = fgets($file);
          $i = 0;
          for($i=0;$i<strlen($line);$i++){
            if(substr($line,$i,1)==' ') break;
          }
          $name=substr($line,0,$i);
          if(!strcmp($name,$_POST['name'])){
            echo '<script>alert("姓名已被使用");history.back();</script>';
            die();
          }
          $i++;
          for(;$i<strlen($line);$i++){
            if(substr($line,$i,1)==' ') break;
          }
          $i++;
          $j = $i;
          for(;$i<strlen($line);$i++){
            if(substr($line,$i,1)==' ') break;
          }
          $email = substr($line,$j,$i-$j);
          if($email===$_POST['email']){
            echo '<script>alert("邮箱已被使用");history.back();</script>';
            die();
          }
          $i++;
          $j = $i;
          for(;$i<strlen($line);$i++){
            if(substr($line,$i,1)==' ') break;
          }
          $phonenum = substr($line,$j,$i-$j);
          if($phonenum===$phone){
            echo '<script>alert("电话已被使用");history.back();</script>';
            die();
          }
        }
        file_put_contents("members.txt",$info,FILE_APPEND);
        echo '<script>alert("报名成功！");history.back();</script>';
        fclose($file);
      }
    }
  }
 ?>
 <!doctype html>

 <head>
 <meta charset="utf-8">
 <link rel="stylesheet" href="style.css">
 </head>

 <body>
 <div id="container">
   <div id="main" role="main">
     <form method="post" action="" >
       <fieldset>

 		<label for="name">your name</label>
         <input type="hidden" name="action" text="register">
         <input type="text" name="name" id="form_css" required autofocus>
    <label for="grade">your grade</label>
         <input type="text" name="grade" id="form_css" required>
 		<label for="grade">your e-mail address</label>
         <input type="text" name="email" id="form_css" required>
    <label for="grade">your phone number</label>
         <input type="text" name="phone" id="form_css" required>
    <label for="grade">department you want to join</label>
         <input type="text" name="department" id="form_css" required>

       </fieldset>
       <fieldset>
         <button type=submit>&nbsp;>></button>
       </fieldset>
     </form>
   </div>
 </div>
 </body>
 </html>
