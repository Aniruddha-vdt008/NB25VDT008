
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) {
        name = n;
        cout << "Person Constructor" << endl;
    }

    void display() {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person {
public:
    Student(string n) : Person(n) {
        cout << "Student Constructor" << endl;
    }
};

class Employee : virtual public Person {
public:
    Employee(string n) : Person(n) {
        cout << "Employee Constructor" << endl;
    }
};

class TA : public Student, public Employee {
public:
    TA(string n) : Person(n), Student(n), Employee(n) {
        cout << "TA Constructor" << endl;
    }
};

int main() {
    TA t("Rahul");
    t.display();

    return 0;
}
