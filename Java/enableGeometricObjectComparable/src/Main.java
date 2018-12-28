public class Main {

    // Main method
    public static void main(String[] args) {
        // Create two comparable circles
        Circle1 circle1 = new Circle1(5);
        Circle1 circle2 = new Circle1(4);

        // Display the max circle
        Circle1 circle = (Circle1)GeometricObject1.max(circle1, circle2);
        System.out.println("The max circle's radius is " +
                circle.getRadius());
        System.out.println(circle);
    }
}

abstract class GeometricObject1 implements Comparable {
    // Implement it
    public int compareTo(Object o) {
        return 0;
    }
    static Circle1 max(Circle1 c1, Circle1 c2) {
        if(c1.getRadius() > c2.getRadius()) return c1;
        else return c2;
    }
}

// Circle.java: The circle class that extends GeometricObject
class Circle1 extends GeometricObject1 {
    // Implement it
    double radius;
    Circle1(double radius) {
        this.radius = radius;
    }
    public double getRadius() {
        return radius;
    }
}