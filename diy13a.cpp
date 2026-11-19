
#include <iostream>
#include <memory>
using namespace std;

class Student {
    string name;

public:
    Student(string n) : name(n) {
        cout << "Student created\n";
    }

    void display() {
        cout << "Student Name: " << name << endl;
    }

    ~Student() {
        cout << "Student destroyed\n";
    }
};

int main() {
    unique_ptr<Student> s1 =
        make_unique<Student>("Asha");

    s1->display();

    unique_ptr<Student> s2 =
        make_unique<Student>("Ravi");

    s2->display();

    return 0;
}
