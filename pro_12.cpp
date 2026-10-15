#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter a word: ";
    cin >> s;

    cout << "Length: " << s.length() << endl;

    cout << "Upper: ";
    for (char c : s)
        cout << (char)toupper(c);
    cout << endl;

    bool pal = true;

    for (size_t i = 0, j = s.size() - 1; i < s.size() - 1; ++i, --j)
    {
        if (s[i] != s[j])
        {
            pal = false;
            break;
        }
    }

    cout << (pal ? "Is" : "Is not") << " a palindrome" << endl;

    size_t pos = s.find("an");

    if (pos != string::npos)
        cout << "\"an\" found at index " << pos << endl;
    else
        cout << "\"an\" not found" << endl;

    return 0;
}