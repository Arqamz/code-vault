#include <iostream>
#include <vector>
#include <climits>

int maxProfitRodCutting(int length, std::vector<int>& prices) {
    std::vector<int> dp(length + 1, 0);

    for (int i = 1; i <= length; i++) {
        int maxVal = INT_MIN;
        for (int j = 1; j <= i; j++) {
            maxVal = std::max(maxVal, prices[j] + dp[i - j]);
        }
        dp[i] = maxVal;
    }

    return dp[length];
}

int main() {
    int length;
    std::cout << "Enter the length of the rod: ";
    std::cin >> length;

    std::vector<int> prices(length + 1);
    std::cout << "Enter the prices for each length: ";
    for (int i = 1; i <= length; i++) {
        std::cin >> prices[i];
    }

    int maxProfit = maxProfitRodCutting(length, prices);
    std::cout << "Maximum profit: " << maxProfit << std::endl;

    return 0;
}
    