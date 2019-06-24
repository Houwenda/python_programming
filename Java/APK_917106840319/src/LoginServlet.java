import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import java.sql.*;

public class LoginServlet extends HttpServlet {
	public static String driver;
	public static String url;
	public static String user;
	public static String password;
	public static Connection conn;
	public static DatabaseMetaData dbma;
	static {
		try {
			driver = "com.mysql.cj.jdbc.Driver";
			url = "jdbc:mysql://127.0.0.1:3306/apk?useSSL=false&serverTimezone=GMT";
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
	public LoginServlet() {
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
		response.sendRedirect("/login.jsp");
		//response.setContentType("text/html");
		//PrintWriter out = response.getWriter();
		//out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
		//out.println("<HTML>");
		//out.println("  <HEAD><TITLE>A Servlet</TITLE></HEAD>");
		//out.println("  <BODY>");
		//out.print("    This is ");
		//out.print(this.getClass());
		//out.println(", using the GET method");
		//out.println("  </BODY>");
		//out.println("</HTML>");
		//out.flush();
		//out.close();
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
		//response.sendRedirect("../login.jsp");
		
		try {
			Statement stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery("select pw from user where name='" + request.getParameter("username") + "';");
			if (rs.next()) {
				String passwd = rs.getString(1);
				if(passwd.equals(request.getParameter("passwd"))) {
					//System.out.println("login succeeded");
					HttpSession sess = request.getSession();
					int isLogin = 1;
					sess.setAttribute("login",isLogin);
					
					// 提取apkset保存到session
					rs = stmt.executeQuery("select * from apk;");
					String tr = "";
					while(rs.next()) {
						tr = tr + "<tr><td>" +
							rs.getString(1) + "</td><td>" + 
							rs.getString(2) + "</td><td>" + 
							rs.getString(3) + "</td><td>" + 
							rs.getString(4) + "</td><td>" + 
							rs.getString(5) + "</td></tr>";
					}
					sess.setAttribute("apkset", tr);
					response.sendRedirect("../main.jsp");
				}
				else {
					System.out.println("login failed");			
					System.out.println(passwd);
					System.out.println(request.getParameter("passwd"));
					response.sendRedirect("../login.jsp?r=1");
				}
			}
			else {
				System.out.println("login failed");
				response.sendRedirect("../login.jsp?r=1");
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
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
