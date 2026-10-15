#include <iostream>
using namespace std;

class Tracker
{
    int id;

public:
    Tracker(int i) : id(i)
    {
        cout << "construct #" << id << endl;
    }

    ~Tracker()
    {
        cout << "destruct #" << id << endl;
    }
};

int main()
{
    cout << "enter block\n";

    {
        Tracker a(1), b(2);
        cout << "...working..." << endl;
    }

    cout << "left block\n";

    return 0;
}