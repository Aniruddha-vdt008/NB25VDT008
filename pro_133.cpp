

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;
mutex m;

void addSafe(int times) {
    for (int i = 0; i < times; i++) {
        lock_guard<mutex> lk(m);
        counter++;
    }
}

int main() {
    thread t1(addSafe, 100000);
    thread t2(addSafe, 100000);

    t1.join();
    t2.join();

    cout << "Counter = " << counter << endl;
    cout << "Expected = 200000" << endl;

    return 0;
}

