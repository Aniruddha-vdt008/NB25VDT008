#include <iostream>
using namespace std;

class Rectangle {
private:
    double length, width;

public:
    void setLength(double l) {
        if (l >= 0)
            length = l;
        else
            cout << "Invalid length!" << endl;
    }

    void setWidth(double w) {
        if (w >= 0)
            width = w;
        else
            cout << "Invalid width!" << endl;
    }

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle r;

    r.setLength(10);
    r.setWidth(5);

    cout << "Area = " << r.area() << endl;
    cout << "Perimeter = " << r.perimeter() << endl;

    return 0;
}