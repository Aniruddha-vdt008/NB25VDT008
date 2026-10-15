#include <iostream>
using namespace std;

class Tracer {
private:
    int id;

public:
    Tracer(int n) {
        id = n;
        cout << "Tracer " << id << " created" << endl;
    }

    ~Tracer() {
        cout << "Tracer " << id << " destroyed" << endl;
    }
};

int main() {
    for (int i = 1; i <= 3; i++) {
        Tracer* t = new Tracer(i);

        // Use the object here

        delete t;
    }

    cout << "End of program" << endl;

    return 0;
}