#include <iostream>
using namespace std;

class Widget
{
    int id;
    static int count;

public:
    Widget()
    {
        id = ++count;
        cout << "created " << id << endl;
    }

    ~Widget()
    {
        cout << "destroyed " << id << endl;
        --count;
    }

    static int alive()
    {
        return count;
    }
};

int Widget::count = 0;

int main()
{
    Widget a, b;

    cout << "alive = " << Widget::alive() << endl;

    {
        Widget c;

        cout << "alive = " << Widget::alive() << endl;
    }

    cout << "alive = " << Widget::alive() << endl;

    return 0;
}