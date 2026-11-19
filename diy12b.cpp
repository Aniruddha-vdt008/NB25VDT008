
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    int n, num;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter numbers:\n";

    for (int i = 0; i < n; i++) {
        cin >> num;
        pq.push(num);
    }

    cout << "Top 3 largest numbers:\n";

    for (int i = 0; i < 3 && !pq.empty(); i++) {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}
