
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ofstream out("marks.csv");

    out << "Asha,91\n"
        << "Ravi,78\n"
        << "Meera,88\n";

    out.close();

    ifstream in("marks.csv");

    if (!in) {
        cerr << "open failed\n";
        return 1;
    }

    string line;

    while (getline(in, line)) {
        stringstream ss(line);

        string name, marks;

        getline(ss, name, ',');
        getline(ss, marks, ',');

        cout << name << " => " << marks << endl;
    }

    return 0;
}
