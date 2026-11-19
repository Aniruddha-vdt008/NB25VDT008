
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> freq;

    int n;
    string word;

    cout << "Enter number of words: ";
    cin >> n;

    cout << "Enter words:\n";

    for (int i = 0; i < n; i++) {
        cin >> word;
        freq[word]++;
    }

    cout << "\nWord Frequencies:\n";

    for (auto p : freq) {
        cout << p.first << " : "
             << p.second << endl;
    }

    string mostFrequent;
    int maximum = 0;

    for (auto p : freq) {
        if (p.second > maximum) {
            maximum = p.second;
            mostFrequent = p.first;
        }
    }

    cout << "\nMost frequent word: "
         << mostFrequent << endl;

    cout << "Frequency: " << maximum << endl;

    return 0;
}
