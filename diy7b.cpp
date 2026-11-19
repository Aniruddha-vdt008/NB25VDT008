
#include <iostream>
using namespace std;

class Shape {
protected:
    string name;

public:
    Shape() {
        name = "Shape";
        cout << "Shape Constructor" << endl;
    }
};

class Polygon : public Shape {
protected:
    int sides;

public:
    Polygon(int s) {
        sides = s;
        cout << "Polygon Constructor" << endl;
    }
};

class Rectangle : public Polygon {
    int length, breadth;

public:
    Rectangle(int l, int b) : Polygon(4) {
        length = l;
        breadth = b;
        cout << "Rectangle Constructor" << endl;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Sides: " << sides << endl;
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Area: " << length * breadth << endl;
    }
};

int main() {
    Rectangle r(10, 5);
    r.display();

    return 0;
}
