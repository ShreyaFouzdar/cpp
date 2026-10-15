#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string s, word;
    stringstream ss;

    cout << "Enter a sentence: ";
    getline(cin, s);

    ss << s;

    string words[100];
    int n = 0;

    while (ss >> word)
        words[n++] = word;

    for (int i = n - 1; i >= 0; i--)
        cout << words[i] << " ";

    return 0;
}