#include <iostream>
#include <vector>
#include <algorithm>

std::string longestCommonSubsequence(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    std::vector<std::vector<char>> direction(m + 1, std::vector<char>(n + 1, ' '));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                direction[i][j] = '\\'; // Diagonal arrow
            } else {
                if (dp[i - 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    direction[i][j] = '|'; // Up arrow
                } else {
                    dp[i][j] = dp[i][j - 1];
                    direction[i][j] = '-'; // Left arrow
                }
            }
        }
    }

    std::string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (direction[i][j] == '\\') {
            lcs = str1[i - 1] + lcs;
            i--;
            j--;
        } else if (direction[i][j] == '|') {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    std::string str1 = "ABCD";
    std::string str2 = "ACDF";

    std::string lcs = longestCommonSubsequence(str1, str2);

    std::cout << "Longest Common Subsequence: " << lcs << std::endl;
    std::cout << "Length of Longest Common Subsequence: " << lcs.length() << std::endl;

    return 0;
}