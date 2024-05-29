#include <iostream>
#include <vector>
#include <string>

std::vector<int> calculateZArray(const std::string& str) {
    int n = str.length();
    std::vector<int> zArray(n, 0);
    int left = 0, right = 0;

    for (int i = 1; i < n; ++i) {
        if (i > right) {
            left = right = i;
            while (right < n && str[right - left] == str[right]) {
                right++;
            }
            zArray[i] = right - left;
            right--;
        } else {
            int k = i - left;
            if (zArray[k] < right - i + 1) {
                zArray[i] = zArray[k];
            } else {
                left = i;
                while (right < n && str[right - left] == str[right]) {
                    right++;
                }
                zArray[i] = right - left;
                right--;
            }
        }
    }

    return zArray;
}

std::vector<int> zArrayStringMatching(const std::string& text, const std::string& pattern) {
    std::string concat = pattern + "$" + text;
    int n = concat.length();
    int patternLength = pattern.length();
    std::vector<int> zArray = calculateZArray(concat);
    std::vector<int> matches;

    for (int i = patternLength + 1; i < n; ++i) {
        if (zArray[i] == patternLength) {
            matches.push_back(i - patternLength - 1);
        }
    }

    return matches;
}

int main() {
    std::string text = "ababcababcabc";
    std::string pattern = "abc";
    std::vector<int> matches = zArrayStringMatching(text, pattern);

    if (matches.empty()) {
        std::cout << "No matches found." << std::endl;
    } else {
        std::cout << "Pattern found at positions: ";
        for (int match : matches) {
            std::cout << match << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}