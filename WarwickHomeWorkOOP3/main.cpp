//Lesson C Task A
#include <iostream>

class Figure {
protected:
    double a;
    double h;
    const double PI = 3.1415;
    virtual double area() = 0;
public:
    Figure() { }                    //for circle
    Figure(double a, double h) { }  //for all other
};

class Circle : public Figure {
    double radius;
public:
    Circle(double radius) : Figure () {
        this->radius = radius;
    }
    double area() override {
    return (PI*radius*radius);
    }
};

class Parrallelogram : public Figure {
public:
    Parrallelogram(double a, double h) : Figure(a,h) {
        this->a = a;
        this->h = h;
    }
    double area() override {
    return (a*h);
    }
};

class Rectangle : public Parrallelogram {
public:
    Rectangle(double a, double h) : Parrallelogram(a,h) {
        this->a = a;
        this->h = h;
    }
    double area() override {
    return (a*h);
    }
};

class Square : public Rectangle {
public:
    Square(double a) : Rectangle(a,a) {
        this->a = a;
    }
    double area() override {
    return (a*a);
    }
};

class Rhombus : public Rectangle {
public:
    Rhombus(double a, double h) : Rectangle(a,h) {
        this->a = a;
        this->h = h;
    }
    double area() override {
    return (a*h);
    }
};

int main()
{
    Circle c1(5.0);
    std::cout << c1.area() << std::endl;
    Parrallelogram p1(4, 5);
    std::cout << p1.area() << std::endl;
    Rectangle r1(7,9);
    std::cout << r1.area() << std::endl;
    Square s1(10);
    std::cout << s1.area() << std::endl;
    Rhombus rh1(8, 7);
    std::cout << rh1.area() << std::endl;
    
    return 0;
}
