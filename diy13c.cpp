
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;
mutex m;

void increment(int n) {
    for (int i = 0; i < n; i++) {
        lock_guard<mutex> lock(m);
        counter++;
    }
}

int main() {
    thread t1(increment, 100000);
    thread t2(increment, 100000);

    t1.join();
    t2.join();

    cout << "Final Counter: " << counter << endl;
    cout << "Expected Counter: 200000" << endl;

    return 0;
}
