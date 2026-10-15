#include <iostream>
using namespace std;

void swap_ref(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void swap_ptr(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int x = 10, y = 20;

    swap_ref(x, y);
    cout << "After swap ref: x = " << x << ", y = " << y << endl;

    swap_ptr(&x, &y);
    cout << "After swap ptr: x = " << x << ", y = " << y << endl;

    int &alias = x;
    alias = 90;
    cout << "x after alias = " << alias << endl;

    return 0;
}