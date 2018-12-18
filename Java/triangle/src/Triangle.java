public class Triangle {
    double side1 = 1.0;
    double side2 = 1.0;
    double side3 = 1.0;
    public Triangle(){}
    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }
    public double accessor1() {
        return side1;
    }
    public double accessor2() {
        return side2;
    }
    public double accessor3() {
        return side3;
    }
    public double getArea() {
        double p = (side1 + side3 + side2) / 2;
        return Math.sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }
    public double getPerimeter() {
        return side1 + side2 + side3;
    }
    public String toString() {
        return "Triangle: side1 = " + side1 + " side2 = " + side2 + " side3 = " + side3;
    }
}
