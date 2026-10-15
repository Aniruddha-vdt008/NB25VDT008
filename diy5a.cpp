#include <iostream>
using namespace std;

class Counter {
private:
    static int totalCreated;
    static int currentlyAlive;

public:
    Counter() {
        totalCreated++;
        currentlyAlive++;
    }

    ~Counter() {
        currentlyAlive--;
    }

    static void displayCounts() {
        cout << "Total objects created: "
             << totalCreated << endl;
        cout << "Currently alive: "
             << currentlyAlive << endl;
    }
};

// Initialize static members
int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    Counter::displayCounts();

    Counter c1, c2;
    Counter::displayCounts();

    {
        Counter c3;
        Counter::displayCounts();
    }

    cout << "After c3 is destroyed:" << endl;
    Counter::displayCounts();

    return 0;
}