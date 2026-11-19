
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int marks;
};

int main() {
    ofstream out("students.txt");

    out << "Asha 85\n";
    out << "Ravi 95\n";
    out << "Meera 90\n";

    out.close();

    Student s[3];

    ifstream in("students.txt");

    for (int i = 0; i < 3; i++) {
        in >> s[i].name >> s[i].marks;
    }

    in.close();

    int topper = 0;

    for (int i = 1; i < 3; i++) {
        if (s[i].marks > s[topper].marks)
            topper = i;
    }

    cout << "Student Records:\n";

    for (int i = 0; i < 3; i++) {
        cout << s[i].name << " "
             << s[i].marks << endl;
    }

    cout << "\nTopper: " << s[topper].name;
    cout << "\nMarks: " << s[topper].marks << endl;

    return 0;
}
