public class Main {

    public static void main(String[] args) {
        Circle circle = new Circle(0, 0, 1);
        circle.setColor("yellow");
        circle.setFilled(true);

        System.out.println(circle);
        System.out.println("The area is " + circle.getArea());
        System.out.println("The perimeter is " + circle.getPerimeter());
        System.out.println("The filled is " + circle.isFilled());
        System.out.println("The color is " + circle.getColor());
        System.out.println(circle);
    }
}
