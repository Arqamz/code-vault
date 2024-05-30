#include <iostream>
#include <vector>
#include <algorithm>

int longestPalindromicSubsequence(const std::string& str) {
    int n = str.length();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (str[i] == str[j] && len == 2) {
                dp[i][j] = 2;
            } else if (str[i] == str[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = std::max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    std::string str = "abcbda";
    int length = longestPalindromicSubsequence(str);
    std::cout << "Length of the longest palindromic subsequence: " << length << std::endl;

    return 0;
}