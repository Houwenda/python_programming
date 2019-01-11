public class Main {
    public static void main(String[] args) {
        test[] c=new test[199];
        A a;
        for(int i=0;i<199;i++){
           c[i]=new test();
           a=c[i];
           a.setName("1");
           System.out.println(a.getName());
        }
    }
}

class test implements A{
    String Name;

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }
}
interface A{
    String getName();
    void setName(String name);
}