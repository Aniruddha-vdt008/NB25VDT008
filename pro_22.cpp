#include <iostream>
#include <string>
using namespace std;

void logMsg(const string &msg, int level)
{
    const string logs[] = {"INFO", "WARN", "ERROR"};

    cout << "[" << logs[level] << "] " << msg << endl;
}

double interest(double principal, double years,
                double rate = 7.5)
{
    return principal * rate * years / 100.0;
}

int main()
{
    logMsg("System started", 0);
    logMsg("Cache memory", 2);

    cout << "Interest = " << interest(10000, 2)
         << endl;

    cout << "Interest = " << interest(10000, 2, 9.0)
         << endl;

    return 0;
}