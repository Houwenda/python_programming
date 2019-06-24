import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DatabaseMetaData;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class APKManagerServlet extends HttpServlet {
	public static String driver;
	public static String url;
	public static String user;
	public static String password;
	public static Connection conn;
	public static DatabaseMetaData dbma;
	static {
		try {
			driver = "com.mysql.cj.jdbc.Driver";
			url = "jdbc:mysql://127.0.0.1:3306/apk?useSSL=false&serverTimezone=GMT&useUnicode=true&characterEncoding=utf8";
			user = "root";
			password = "root";
			Class.forName(driver);
			conn = DriverManager.getConnection(url, user, password);
			//System.out.println(" mysql connection established");
		} catch (ClassNotFoundException classnotfoundexception) {
			classnotfoundexception.printStackTrace();
			System.out.println("db: " + classnotfoundexception.getMessage());
		} catch (SQLException sqlexception) {
			System.err.println("db.getconn() exception caught: " + sqlexception.getMessage());
		}
		//try {
		//	DBConn.dbma = conn.getMetaData();
		//} catch (SQLException e) {
		//	e.printStackTrace();
		//}
	}
	/**
		 * Constructor of the object.
		 */
	public APKManagerServlet() {
		super();
	}

	/**
		 * Destruction of the servlet. <br>
		 */
	public void destroy() {
		super.destroy(); // Just puts "destroy" string in log
		// Put your code here
	}

	/**
		 * The doGet method of the servlet. <br>
		 *
		 * This method is called when a form has its tag value method equals to get.
		 * 
		 * @param request the request send by the client to the server
		 * @param response the response send by the server to the client
		 * @throws ServletException if an error occurred
		 * @throws IOException if an error occurred
		 */
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
		out.println("<HTML>");
		out.println("  <HEAD><TITLE>A Servlet</TITLE></HEAD>");
		out.println("  <BODY>");
		out.print("    This is ");
		out.print(this.getClass());
		out.println(", using the GET method");
		out.println("  </BODY>");
		out.println("</HTML>");
		out.flush();
		out.close();
	}

	/**
		 * The doPost method of the servlet. <br>
		 *
		 * This method is called when a form has its tag value method equals to post.
		 * 
		 * @param request the request send by the client to the server
		 * @param response the response send by the server to the client
		 * @throws ServletException if an error occurred
		 * @throws IOException if an error occurred
		 */
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		String action = request.getParameter("action");
		if(action.equals("add")) {
			String name = request.getParameter("name");
			String type = request.getParameter("type");
			String developer = request.getParameter("developer");
			String time = request.getParameter("time");
			int id = ((int) (Math.random() * (1000-100))) + 100;
			//System.out.println(name);
			//System.out.println(type);
			//System.out.println(developer);
			//System.out.println(time);
			//System.out.println("insert into apk(id,name,type,developer,time) values(" +
			//		id + ",'" + name + "','" + type + "','" + developer + "','" + time + "');");
			try {
				Statement stmt = conn.createStatement();
				int suc = stmt.executeUpdate("insert into apk(id,name,type,developer,time) values(" +
						id + ",'" + name + "','" + type + "','" + developer + "','" + time + "');");
				if(suc != 0) {
					// 提取apkset保存到session
					ResultSet rs = stmt.executeQuery("select * from apk;");
					String tr = "";
					while(rs.next()) {
						tr = tr + "<tr><td>" +
							rs.getString(1) + "</td><td>" + 
							rs.getString(2) + "</td><td>" + 
							rs.getString(3) + "</td><td>" + 
							rs.getString(4) + "</td><td>" + 
							rs.getString(5) + "</td></tr>";
					}
					HttpSession sess = request.getSession();
					sess.setAttribute("apkset", tr);
					//response.sendRedirect("../main.jsp");	
					response.setContentType("text/html");
					response.setCharacterEncoding("utf-8");
					PrintWriter out = response.getWriter();
					out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
					out.println("<html>");
					out.println("<head>");
					//out.println("<meta http-equiv='refresh' content='5;url=../main.jsp'> ");
					out.println("</head>");
					out.println("<script>");
					out.println("alert('添加成功');window.location.href='../main.jsp'");
					out.println("</script>");
					//out.println("<body>");
					//out.println("添加成功，将会在3秒后自动调转至main.jsp");
					//out.println("</body>");
					out.println("</html>");
				}else {
					response.setContentType("text/html");
					response.setCharacterEncoding("utf-8");
					PrintWriter out = response.getWriter();
					out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
					out.println("<html>");
					out.println("<head>");
					//out.println("<meta http-equiv='refresh' content='5;url=../main.jsp'> ");
					out.println("</head>");
					out.println("<script>");
					out.println("alert('添加失败');window.location.href='../main.jsp'");
					out.println("</script>");
					out.println("</html>");
				}
			} catch (SQLException e) {
				response.setContentType("text/html");
				response.setCharacterEncoding("utf-8");
				PrintWriter out = response.getWriter();
				out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
				out.println("<html>");
				out.println("<head>");
				//out.println("<meta http-equiv='refresh' content='5;url=../main.jsp'> ");
				out.println("</head>");
				out.println("<script>");
				out.println("alert('添加失败');window.location.href='../main.jsp'");
				out.println("</script>");
				out.println("</html>");
				// TODO Auto-generated catch block
				e.printStackTrace();
			}		
		}
		
		
		else if(action.equals("modify")) {
			String name = request.getParameter("name");
			String type = request.getParameter("type");
			String developer = request.getParameter("developer");
			String time = request.getParameter("time");
			int id = Integer.parseInt(request.getParameter("id"));
			
			//System.out.println(name);
			//System.out.println(type);
			//System.out.println(developer);
			//System.out.println(time);
			try {
				Statement stmt = conn.createStatement();
				int suc = stmt.executeUpdate("update apk set name='" + name + "',type='" + type +
						"',developer='" + developer + "',time='" + time + "' where id = " + id + ";");
				//System.out.println(suc);
				if(suc != 0) {
					// 提取apkset保存到session
					ResultSet rs = stmt.executeQuery("select * from apk;");
					String tr = "";
					while(rs.next()) {
						tr = tr + "<tr><td>" +
							rs.getString(1) + "</td><td>" + 
							rs.getString(2) + "</td><td>" + 
							rs.getString(3) + "</td><td>" + 
							rs.getString(4) + "</td><td>" + 
							rs.getString(5) + "</td></tr>";
					}
					HttpSession sess = request.getSession();
					sess.setAttribute("apkset", tr);
					//response.sendRedirect("../main.jsp");	
					response.setContentType("text/html");
					response.setCharacterEncoding("utf-8");
					PrintWriter out = response.getWriter();
					out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
					out.println("<html>");
					out.println("<head>");
					//out.println("<meta http-equiv='refresh' content='5;url=../main.jsp'> ");
					out.println("</head>");
					out.println("<script>");
					out.println("alert('修改成功');window.location.href='../main.jsp'");
					out.println("</script>");
					//out.println("<body>");
					//out.println("修改成功，将会在3秒后自动调转至main.jsp");
					//out.println("</body>");
					out.println("</html>");
				}else {
					response.setContentType("text/html");
					response.setCharacterEncoding("utf-8");
					PrintWriter out = response.getWriter();
					out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
					out.println("<html>");
					out.println("<head>");
					//out.println("<meta http-equiv='refresh' content='5;url=../main.jsp'> ");
					out.println("</head>");
					out.println("<script>");
					out.println("alert('修改失败');window.location.href='../main.jsp'");
					out.println("</script>");
					out.println("</html>");
				}
				
			} catch (SQLException e) {
				response.setContentType("text/html");
				response.setCharacterEncoding("utf-8");
				PrintWriter out = response.getWriter();
				out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
				out.println("<html>");
				out.println("<head>");
				//out.println("<meta http-equiv='refresh' content='5;url=../main.jsp'> ");
				out.println("</head>");
				out.println("<script>");
				out.println("alert('修改失败');window.location.href='../main.jsp'");
				out.println("</script>");
				out.println("</html>");
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		
		else if(action.equals("del")) {
			int id = 0;
			try {
				id = Integer.parseInt(request.getParameter("id"));
			} catch (java.lang.NumberFormatException e) {
				response.setContentType("text/html");
				response.setCharacterEncoding("utf-8");
				PrintWriter out = response.getWriter();
				out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
				out.println("<html>");
				out.println("<head>");
				//out.println("<meta http-equiv='refresh' content='5;url=../main.jsp'> ");
				out.println("</head>");
				out.println("<script>");
				out.println("alert('删除失败');window.location.href='../main.jsp'");
				out.println("</script>");
				out.println("</html>");
				e.printStackTrace();
			}
			try {
				Statement stmt = conn.createStatement();
				int suc = stmt.executeUpdate("delete from apk where id=" + id + ";");
				//System.out.println(suc);
				if(suc != 0) {
					// 提取apkset保存到session
					ResultSet rs = stmt.executeQuery("select * from apk;");
					String tr = "";
					while(rs.next()) {
						tr = tr + "<tr><td>" +
							rs.getString(1) + "</td><td>" + 
							rs.getString(2) + "</td><td>" + 
							rs.getString(3) + "</td><td>" + 
							rs.getString(4) + "</td><td>" + 
							rs.getString(5) + "</td></tr>";
					}
					HttpSession sess = request.getSession();
					sess.setAttribute("apkset", tr);
					//response.sendRedirect("../main.jsp");	
					response.setContentType("text/html");
					response.setCharacterEncoding("utf-8");
					PrintWriter out = response.getWriter();
					out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
					out.println("<html>");
					out.println("<head>");
					//out.println("<meta http-equiv='refresh' content='5;url=../main.jsp'> ");
					out.println("</head>");
					out.println("<script>");
					out.println("alert('删除成功');window.location.href='../main.jsp'");
					out.println("</script>");
					//out.println("<body>");
					//out.println("修改成功，将会在3秒后自动调转至main.jsp");
					//out.println("</body>");
					out.println("</html>");
				}
				else {
					response.setContentType("text/html");
					response.setCharacterEncoding("utf-8");
					PrintWriter out = response.getWriter();
					out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
					out.println("<html>");
					out.println("<head>");
					//out.println("<meta http-equiv='refresh' content='5;url=../main.jsp'> ");
					out.println("</head>");
					out.println("<script>");
					out.println("alert('删除失败');window.location.href='../main.jsp'");
					out.println("</script>");
					out.println("</html>");
				}
			} catch (SQLException e){
				response.setContentType("text/html");
				response.setCharacterEncoding("utf-8");
				PrintWriter out = response.getWriter();
				out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
				out.println("<html>");
				out.println("<head>");
				//out.println("<meta http-equiv='refresh' content='5;url=../main.jsp'> ");
				out.println("</head>");
				out.println("<script>");
				out.println("alert('删除失败');window.location.href='../main.jsp'");
				out.println("</script>");
				out.println("</html>");
				e.printStackTrace();
			}
		}
			
			
			
			
		else {
			response.setContentType("text/html");
			PrintWriter out = response.getWriter();
			out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
			out.println("<HTML>");
			out.println("  <HEAD><TITLE>A Servlet</TITLE></HEAD>");
			out.println("  <BODY>");
			out.print("    This is ");
			out.print(this.getClass());
			out.println(", using the POST method");
			out.println("  </BODY>");
			out.println("</HTML>");
			out.flush();
			out.close();
		}
	}

	/**
		 * Initialization of the servlet. <br>
		 *
		 * @throws ServletException if an error occurs
		 */
	public void init() throws ServletException {
		// Put your code here
	}

}
