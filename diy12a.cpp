
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<pair<string, int>> v = {
        {"Asha", 85},
        {"Ravi", 95},
        {"Meera", 75},
        {"John", 90}
    };

    sort(v.begin(), v.end(),
         [](const pair<string, int>& a,
            const pair<string, int>& b) {
             return a.second < b.second;
         });

    cout << "Sorted pairs:\n";

    for (auto p : v) {
        cout << p.first << " "
             << p.second << endl;
    }

    return 0;
}
