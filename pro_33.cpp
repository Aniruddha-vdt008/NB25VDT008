#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    Point add(const Point &p) const
    {
        return Point(x + p.x, y + p.y);
    }

    Point &setX(const int v)
    {
        x = v;
        return *this;
    }

    Point &setY(const int v)
    {
        y = v;
        return *this;
    }

    void show() const
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

// Pass by reference
void shiftByReference(Point &p)
{
    p.setX(100);
}

// Pass by value
void shiftByValue(Point p)
{
    p.setX(-1);
}

int main()
{
    Point a(1, 2);
    Point b(3, 4);

    Point c = a.add(b);

    cout << "c = ";
    c.show();

    cout << "a = ";
    a.show();

    cout << "b = ";
    b.show();

    shiftByReference(a);

    cout << "After shiftByReference(a): ";
    a.show();

    shiftByValue(b);

    cout << "After shiftByValue(b): ";
    b.show();

    return 0;
}