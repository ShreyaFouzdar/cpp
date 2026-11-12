
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> freq;

    string word;

    cout << "Enter words (type end to stop):" << endl;

    while (cin >> word && word != "end") {
        freq[word]++;
    }

    string mostFrequent;
    int maxCount = 0;

    cout << "\nWord Frequencies:" << endl;

    for (auto item : freq) {
        cout << item.first << ": " << item.second << endl;

        if (item.second > maxCount) {
            maxCount = item.second;
            mostFrequent = item.first;
        }
    }

    if (maxCount > 0) {
        cout << "Most frequent word: " << mostFrequent << endl;
        cout << "Count: " << maxCount << endl;
    }

    return 0;
}
