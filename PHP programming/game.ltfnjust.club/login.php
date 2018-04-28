<!doctype html>
<html>

<head>
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" href="src/gamepage.css">
	<link rel="shortcut icon" href="src/logo.ico">
	<link rel="bookmark" href="src/logo.ico">
	<title>LTF - Lose the Flag</title>
</head>
<?php
if(!isset($_POST["login"]))  //未提交登录数据
{
?>
<body>
	<div class="login">
	  <div class="login_title">
	    <span>请登录</span>
	  </div>
	  <div class="login_fields">

	    <div class="login_user">
	      <div class="icon">
	        <img alt="" src="src/user_icon_copy.png">
	      </div>
        <form action="login.php" method="post">
	          <input name="login" placeholder="用户名" maxlength="16" autocomplete="off"  type="text">
        </form>
	        <div class="validation">
	          <img alt="" src="src/tick.png">
	        </div>
	    </div>

	    <div class="login_password">
	      <div class="icon">
	        <img alt="" src="src/lock_icon_copy.png">
	      </div>
        <form action="login.php" method="post">
	         <input name="pwd" placeholder="密码" maxlength="16" autocomplete="off" type="text">
        </form>
	    </div>

	    <div></div>
	    <div class="login_submit">
        <form action="login.php" method="post">
	         <input value="登录" type="submit">
        </form>
<!--        <input value="注册" type="button" herf="#register">  -->
      </div>
	  </div>


<!--
			<div id="register" style="display:none">

			<form action="#" method="post">
				<input name="Name" placeholder="用户名" required="" type="text">
				<input name="Email" class="email" placeholder="邮件" required="" type="text">
				<input name="Password" class="password" placeholder="密码" required="" type="password">
				<input name="Password" class="password" placeholder="重复密码" required="" type="password">
				<input value="点击注册" type="submit">
			</form>
	       </div>
-->


	</div>
</body>
</html>
<?php
}
else {
  $user = $_POST["login"];
  $pwd = $_POST["pwd"];
  $sql="SELECT COUNT(id) FROM $game_user WHERE name='$user' AND pass='$pwd'";
  $result=$mysqli->query($sql);
  $num=$result->num_rows;
  if($num==0)  //判断用户密码是否正确
  {
    echo "用户名或密码错误！<p>";
    echo "单击<a href='login.php'>这里</a>重新登录";
  }
  else {
    setcookie("user",$user);
    echo "登录成功！<p>";
    echo "单击<a href='index.php'>这里</a>进入游戏大厅";
  }
}
?>
