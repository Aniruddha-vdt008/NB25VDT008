
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;

public:
    Circle(double r) : r(r) {}

    double area() const override {
        return 3.14159 * r * r;
    }
};

class Square : public Shape {
    double s;

public:
    Square(double s) : s(s) {}

    double area() const override {
        return s * s;
    }
};

class Triangle : public Shape {
    double b, h;

public:
    Triangle(double b, double h)
        : b(b), h(h) {}

    double area() const override {
        return 0.5 * b * h;
    }
};

unique_ptr<Shape> makeShape(string name) {
    if (name == "circle")
        return make_unique<Circle>(5);

    else if (name == "square")
        return make_unique<Square>(4);

    else if (name == "triangle")
        return make_unique<Triangle>(6, 8);

    return nullptr;
}

int main() {
    vector<unique_ptr<Shape>> shapes;

    int n;
    string name;

    cout << "Enter number of shapes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter shape (circle/square/triangle): ";
        cin >> name;

        auto shape = makeShape(name);

        if (shape)
            shapes.push_back(move(shape));
        else
            cout << "Invalid shape!\n";
    }

    cout << "\nShape Areas:\n";

    for (const auto& s : shapes)
        cout << s->area() << endl;

    return 0;
}
