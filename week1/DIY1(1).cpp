#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s;
    int v = 0, c = 0;

    cout << "Enter a sentence: ";
    getline(cin, s);

    for (char ch : s)
    {
        ch = tolower(ch);

        if (ch >= 'a' && ch <= 'z')
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u')
                v++;
            else
                c++;
        }
    }

    cout << "Vowels = " << v << endl;
    cout << "Consonants = " << c << endl;

    return 0;
}