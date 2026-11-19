
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("nums.txt");

    out << "10 20 30 40 50";
    out.close();

    ifstream in("nums.txt");

    int num, count = 0, sum = 0;
    int minimum = 0, maximum = 0;

    while (in >> num) {
        if (count == 0) {
            minimum = maximum = num;
        }

        if (num < minimum)
            minimum = num;

        if (num > maximum)
            maximum = num;

        sum += num;
        count++;
    }

    cout << "Count: " << count << endl;
    cout << "Sum: " << sum << endl;
    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;

    in.close();

    return 0;
}
