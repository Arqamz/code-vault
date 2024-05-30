#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";
    }
    
    int n = strs.size();
    int m = strs[0].size();
    
    // Create a 2D table to store the lengths of common prefixes
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    
    // Initialize the first row of the table
    for (int i = 0; i < m; i++) {
        if (strs[0][i] == strs[0][0]) {
            dp[0][i] = 1;
        } else {
            break;
        }
    }
    
    // Fill the table using dynamic programming
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (strs[i][j] == strs[0][j]) {
                dp[i][j] = dp[i-1][j] + 1;
            } else {
                break;
            }
        }
    }
    
    // Find the minimum length of common prefix
    int minLen = m;
    for (int i = 0; i < n; i++) {
        minLen = std::min(minLen, dp[i][m-1]);
    }
    
    // Return the longest common prefix
    return strs[0].substr(0, minLen);
}

int main() {
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::string longestPrefix = longestCommonPrefix(strs);
    std::cout << "Longest Common Prefix: " << longestPrefix << std::endl;
    
    return 0;
}