class GeometricObject {
    private String color = "white";
    private boolean filled = false;
    private java.util.Date dateCreated = new java.util.Date();
    GeometricObject() {}
    GeometricObject(String color, boolean filled) {
        this.color = color;
        this.filled = filled;
    }
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }
    public boolean isFilled() {
        return filled;
    }
    public void setFilled(boolean filled) {
        this.filled = filled;
    }
    public java.util.Date getDateCreated() {
        return dateCreated;
    }
}

class Circle extends GeometricObject{
    double radius = 0.0;
    double x = 0.0;
    double y = 0.0;
    Circle(){}
    Circle(double x, double y, double radius) {
        this.x = x;
        this.y = y;
        this.radius = radius;
    }
    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
    double getRadius() {
        return radius;
    }
    double getArea() {
        return Math.PI * radius * radius;
    }
    double getPerimeter() {
        return 2 * Math.PI * radius;
    }
    public String toString() {
        return " Circle: x = " + x + " y = " + y + " radius = " + radius;
    }
}