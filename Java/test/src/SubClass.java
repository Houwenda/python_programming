import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

class SuperClass {
    int x;
    void method0() {method1();}
    void method1() {x = 11;}
}
public class SubClass extends SuperClass{
    int x;
    void method1() { x = 2;}
    public static void main(String[] args) {
        SubClass rSub = new SubClass();
        SuperClass rSuper = rSub;
        rSub.method0();
        System.out.println(rSuper.x + "," + rSub.x);
    }
}