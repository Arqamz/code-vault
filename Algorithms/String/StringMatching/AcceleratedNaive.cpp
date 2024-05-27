#include <iostream>
#include <string>

bool acceleratedNaiveStringMatching(const std::string& text, const std::string& pattern) {
    int i = 0, j = 0;
    int textLength = text.length();
    int patternLength = pattern.length();

    while (i < textLength) {
        if (text[i] == pattern[j]) {
            j++;
            if (j == patternLength) {
                return true;
            }
        } else {
            j = 0;
        }
        i++;
    }

    return false;
}

int main() {
    std::string text = "Hello, world!";
    std::string pattern = "world";

    if (acceleratedNaiveStringMatching(text, pattern)) {
        std::cout << "Pattern found in the text." << std::endl;
    } else {
        std::cout << "Pattern not found in the text." << std::endl;
    }

    return 0;
}