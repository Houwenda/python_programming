<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page language="java" import="java.sql.*"%>
<%
    HttpSession sess = request.getSession();
    try {
    	int isLogin = (int)sess.getAttribute("login");
    } catch (java.lang.NullPointerException e){
    	response.sendRedirect("login.jsp");
    	return ;
    }
%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<%
	// 提取出apk列表
	String tr = (String)sess.getAttribute("apkset");
%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'main.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
    <table border="1">
		<tr><td>id</td><td>name</td><td>type</td><td>developer</td><td>time</td></tr>
		<%=tr %> 
    </table>
	<a href="addAPK.jsp">添加</a>
	<a href="modifyAPK.jsp">修改</a>
	<a href="delAPK.jsp">删除</a>

  </body>
</html>
