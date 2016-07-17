/**
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
**/

class Solution {
public:
    int integerBreak(int n) {
        static vector<int> dp;
        if (dp.empty()) {
            dp.push_back(0);
            dp.push_back(0);
            dp.push_back(1);
        }
        if (dp.size() >= n + 1) return dp[n];
        for (int i = dp.size(); i <= n; i ++) {
            int cur = 0;
            for (int k = i - 1; k > 0; k--) {
                cur = max(cur, max(k, dp[k]) * max(i - k, dp[i - k]));
            }
            dp.push_back(cur);
        }
        return dp[n];
    }
};