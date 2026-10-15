#include <iostream>
using namespace std;

// Volume of cube
double volume(double side) {
    return side * side * side;
}

// Volume of cuboid
double volume(double length, double breadth, double height) {
    return length * breadth * height;
}

// Volume of cylinder
double volume(double radius, int height) {
    return 3.14159 * radius * radius * height;
}

int main() {
    cout << "Volume of cube: " << volume(5.0) << endl;
    cout << "Volume of cuboid: " << volume(2.0, 3.0, 4.0) << endl;
    cout << "Volume of cylinder: " << volume(3.0, 5) << endl;

    return 0;
}