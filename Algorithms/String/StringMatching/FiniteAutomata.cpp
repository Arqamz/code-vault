#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> computeTransitionTable(const string& pattern) {
    int m = pattern.length();
    vector<vector<int>> transitionTable(m + 1, vector<int>(256, 0));

    for (int state = 0; state <= m; ++state) {
        for (char ch = 0; ch < 256; ++ch) {
            if (state < m && ch == pattern[state]) {
                transitionTable[state][ch] = state + 1;
            } else {
                string prefix = pattern.substr(0, state);
                prefix += ch;
                int k = min(m, state + 1);
                while (k > 0) {
                    if (pattern.substr(0, k) == prefix.substr(state + 1 - k, k)) {
                        transitionTable[state][ch] = k;
                        break;
                    }
                    --k;
                }
            }
        }
    }

    return transitionTable;
}

vector<int> finiteAutomataStringMatching(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> occurrences;

    vector<vector<int>> transitionTable = computeTransitionTable(pattern);

    int state = 0;
    for (int i = 0; i < n; ++i) {
        state = transitionTable[state][text[i]];
        if (state == m) {
            occurrences.push_back(i - m + 1);
        }
    }

    return occurrences;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    vector<int> occurrences = finiteAutomataStringMatching(text, pattern);

    if (occurrences.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at positions: ";
        for (int pos : occurrences) {
            cout << pos << " ";
        }
        cout << endl;
    }

    return 0;
}