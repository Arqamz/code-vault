#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> buildBadCharTable(const string& pattern) {
    vector<int> badCharTable(256, -1);
    int patternLength = pattern.length();

    for (int i = 0; i < patternLength; i++) {
        badCharTable[pattern[i]] = i;
    }

    return badCharTable;
}

void search(const string& text, const string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    vector<int> badCharTable = buildBadCharTable(pattern);

    int shift = 0;
    while (shift <= textLength - patternLength) {
        int j = patternLength - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            cout << "Pattern found at index " << shift << endl;
            shift += (shift + patternLength < textLength) ? patternLength - badCharTable[text[shift + patternLength]] : 1;
        } else {
            shift += max(1, j - badCharTable[text[shift + j]]);
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    search(text, pattern);

    return 0;
}