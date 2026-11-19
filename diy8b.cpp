
#include <iostream>
#include <fstream>
using namespace std;

class Logger {
public:
    virtual void write(string msg) = 0;
    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void write(string msg) override {
        cout << "Console: " << msg << endl;
    }
};

class FileLogger : public Logger {
public:
    void write(string msg) override {
        ofstream file("log.txt", ios::app);
        file << msg << endl;
        file.close();
        cout << "Written to file" << endl;
    }
};

int main() {
    ConsoleLogger c;
    FileLogger f;

    Logger* l;

    l = &c;
    l->write("System Started");

    l = &f;
    l->write("System Running");

    return 0;
}
