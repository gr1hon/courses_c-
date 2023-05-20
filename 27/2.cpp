#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

enum color{
    None,
    red,
    blue,
    green,
    purple
};

void printColor(color color){
    if (color == color::red)
        cout << "Color: red" << endl;
    else if (color == color::blue)
        cout << "Color: blue" << endl;
    else if (color == color::green)
        cout << "Color: green" << endl;
    else if (color == color::purple)
        cout << "Color: purple" << endl;
}
struct point{
    double x;
    double y;
};

class Shape{
public:
    color color{};
    point center{};
};

class Circle: public Shape{
    double radius;

public:
    double area(){
        return atan(1) * 4 * radius * radius;
    }

    void rectangleAndColor(){
        this->color = color::red;
        printColor(this->color);
        cout << "Upper left angle coordinates of rectangle around the shape: ("
             << this->center.x - radius << "; " << this->center.y + radius << ")\n"
             << "width: " << 2*radius << ", height: " << 2*radius << endl;
    }
    Circle(double in_radius): Shape(), radius(in_radius) {

    }
};



class Triangle: public Shape{
    double side;

public:
    double area(){
        return side * side * sqrt(3) / 4;
    }

    void rectangleAndColor(){
        this->color = color::blue;
        printColor(this->color);
        cout << "Upper left angle coordinates of rectangle around the shape: ("
             << this->center.x - side/2 << "; " << this->center.y + side*2*sqrt(3)/3 << ")\n"
             << "width: " << side << ", height: " << side*sqrt(3)/2 << endl;
    }
    Triangle (double in_side): Shape(), side(in_side){

    }
};

class Rectangle: public Shape {
    double height;
    double width;

public:
    double area() {
        return width * height;
    }

    void rectangleAndColor() {
        if (height == width)
            this->color = color::green;
        else
            this->color = color::purple;
        printColor(this->color);
        cout << "Upper left angle coordinates of rectangle around the shape: ("
             << this->center.x - width / 2 << "; " << this->center.y + height / 2 << ")\n"
             << "width: " << width << ", height: " << height << endl;
    }
    Rectangle(double in_width, double in_height): Shape(), width(in_width), height(in_height){

    }
};

class Square: public Rectangle{

public:

    Square(double in_side): Rectangle(in_side, in_side){

    }
};

int main() {
    string shape;
    cout << "Enter the shape type:(circle, square, triangle or rectangle)" << endl;
    cin >> shape;
    if (shape != "circle" && shape != "square" && shape != "triangle" && shape != "rectangle" ){
        cerr << "Unknown shape type!" << endl;
        return 0;
    }
    double x; double y;
    cout << "Enter the coordinates of the center of the shape:" << endl;
    cin >> x >> y;
    if (shape == "circle"){
        double radius;
        cout << "Enter radius: " << endl;
        cin >> radius;
        auto* circle = new Circle(radius);
        circle->center.x = x;
        circle->center.y = y;
        cout << "Area: " << circle->area() << endl;
        circle->rectangleAndColor();
        delete circle;
    } else if (shape == "square"){
        double side;
        cout << "Enter side: " << endl;
        cin >> side;
        auto* square = new Square(side);
        square->center.x = x;
        square->center.y = y;
        cout << "Area: " << square->area() << endl;
        square->rectangleAndColor();
        delete square;
    } else if (shape == "triangle"){
        double side;
        cout << "Enter side: " << endl;
        cin >> side;
        auto* triangle = new Triangle(side);
        triangle->center.x = x;
        triangle->center.y = y;
        cout << "Area: " << triangle->area() << endl;
        triangle->rectangleAndColor();
        delete triangle;
    } else if (shape == "rectangle"){
        double height; double width;
        cout << "Enter width and height: " << endl;
        cin >> width >> height;
        auto* rectangle = new Rectangle(width, height);
        rectangle->center.x = x;
        rectangle->center.y = y;
        cout << "Area: " << rectangle->area() << endl;
        rectangle->rectangleAndColor();
        delete rectangle;
    }
    cout << "End" << endl;
}
