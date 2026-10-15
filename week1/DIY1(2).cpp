#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string a, b;

    cout << "Enter two words: ";
    cin >> a >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a == b)
        cout << "Anagram";
    else
        cout << "Not anagram";

    return 0;
}