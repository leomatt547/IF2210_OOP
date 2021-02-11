#include <iostream>
using namespace std;

class Shape{
    public:
    Shape();
    virtual ~Shape();
    virtual void draw();
};

class Circle : public Shape {
    public:
    Circle();
    virtual ~Circle();
    virtual void draw();
};

Shape::Shape(){
    cout << "Shape constructor" << endl;
}

Shape::~Shape(){
    cout << "Shape destructor" << endl;
}

void Shape::draw(){
    cout << "Shape draw" << endl;
}

Circle::Circle(){
    cout << "Circle constructor" << endl;
}

Circle::~Circle(){
    cout << "Circle destructor" << endl;
}

void Circle::draw(){
    cout << "Circle draw" << endl;
}

int main(){
    cout << "A:" << endl;
    Shape *sh = new Circle;
    sh->draw();
    delete sh;

    cout << "B:" << endl;
    Shape s;
    Circle c;
    s = c;
    s.draw();

    cout << "C:" << endl;
    Shape *sp;
    sp = &c;
    sp->draw();

    cout << "D:" << endl;
    return 0;
}