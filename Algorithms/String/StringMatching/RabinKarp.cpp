#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int prime = 101;

vector<int> rabinKarp(const string& text, const string& pattern) {
    vector<int> result;
    int n = text.length();
    int m = pattern.length();
    int patternHash = 0;
    int textHash = 0;
    int power = 1;

    for (int i = 0; i <= n - m; i++) {
        if (i == 0) {
            for (int j = 0; j < m; j++) {
                patternHash = (patternHash + pattern[m - 1 - j] * power) % prime;
                textHash = (textHash + text[m - 1 - j] * power) % prime;
                if (j < m - 1) {
                    power = (power * 2) % prime;
                }
            }
        } else {
            textHash = (2 * (textHash - text[i - 1] * power) + text[m + i - 1]) % prime;
        }

        if (patternHash == textHash) {
            bool found = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                result.push_back(i);
            }
        }
    }

    return result;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    vector<int> matches = rabinKarp(text, pattern);

    if (matches.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at positions: ";
        for (int i : matches) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}