
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream out("in.txt");

    out << "Hello World\n";
    out << "C++ Programming\n";
    out << "File Handling\n";

    out.close();

    ifstream in("in.txt");
    ofstream copy("out.txt");

    string line;
    int number = 1;

    while (getline(in, line)) {
        copy << number << ". " << line << endl;
        number++;
    }

    in.close();
    copy.close();

    cout << "File copied successfully with line numbers.\n";

    return 0;
}
