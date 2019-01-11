public class Static {
    static { int x = 5; }
    static int x,y;
    public static void main(String[] args) {
        myMethod();
        System.out.println(x++ + y + ++x);
    }
    public static void myMethod() {
        y = x-- + ++x;
        System.out.println(y);
    }
}
