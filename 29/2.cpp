#include <iostream>
#include <cmath>

using namespace std;

struct  BoundingBoxDimensions{
    double height;
    double width;
};

class Shape{
public:
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual string type() = 0;
};

class Circle: public virtual Shape{
private:
    double radius;

public:
    double square() override{
        return ::atan(1) * 4 * ::pow(radius, 2);
    }

    string type() override{
        return "Circle";
    }

    BoundingBoxDimensions dimensions() override{
        BoundingBoxDimensions box{};
        box.width = radius * 2;
        box.height = radius * 2;
        return box;
    }

    Circle(double radius) : radius(radius){}

};

class Rectangle: public virtual Shape{
private:
    double height;
    double width;
public:
    double square() override{
        return height * width;
    }

    string type() override{
        return "Rectangle";
    }

    BoundingBoxDimensions dimensions() override{
        BoundingBoxDimensions box{};
        box.width = width;
        box.height = height;
        return box;
    }

    Rectangle(double _height, double _width) : height(_height), width(_width){}

};

class Triangle: public virtual Shape{
private:
    double side1;
    double side2;
    double side3;
    double p = (side1 + side2 + side3) / 2;
public:
    double square() override{
        return sqrt(p * (p-side1) * (p-side2) * (p-side3));
    }

    string type() override{
        return "Triangle";
    }

    BoundingBoxDimensions dimensions() override{
        BoundingBoxDimensions box{};
        double r = side1 * side2 * side3 / (4 * sqrt(p * (p-side1) * (p-side2) * (p-side3)));
        double side = r * 2;
        box.width = side;
        box.height = side;
        return box;
    }

    Triangle(double side1, double side2, double side3) : side1(side1), side2(side2), side3(side3) {}
};

void printParams(Shape *shape){
    std::cout <<"Type: " << shape->type() << std::endl;
    std::cout <<"Square: " << shape->square() << std::endl;
    std::cout <<"Width: " << shape->dimensions().width << std::endl;
    std::cout <<"Height: " << shape->dimensions().height << std::endl;
}

int main() {
    Triangle t(3, 4, 5);
    Circle c(1);
    Rectangle r(2,3);
    printParams(&t);
    printParams(&c);
    printParams(&r);
}
