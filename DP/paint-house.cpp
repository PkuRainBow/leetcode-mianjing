class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        vector<vector<int>> dp = costs;
        for (int i = 1; i < dp.size(); ++i) {
            dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
        }
        return min(min(dp.back()[0], dp.back()[1]), dp.back()[2]);
    }
};

/**
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2]is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
**/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        int n = costs.size(), k = costs[0].size(), res = INT_MAX;
        vector<vector<int>> dp = costs;
        for (int i = 1; i < n; ++i) {
            //current house can be painted with k different colors 
            for (int j = 0; j < k; ++j) {
                int mn = INT_MAX;
                //previous house can be painted with other (k-1) different colors
                for (int d = 1; d < k; ++d) {
                    mn = min(mn, dp[i - 1][(j + d) % k]);
                }
                //current with j-th color and smallest previous color
                dp[i][j] += mn;
                //get the smallest cost for the final house 
                if (i == n - 1) res = min(res, dp[i][j]);
            }
        }
        return res;
    }
};