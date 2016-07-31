class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) 
            return 0;
        int i, n = prices.size();
        int result = 0;
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);
        buy[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1] - prices[i - 1] + prices[i]);
            if (result < sell[i])   result = sell[i];
            if (1 == i) buy[i] = buy[0] + prices[0] - prices[1];
            else buy[i] = max(sell[i - 2] - prices[i], buy[i - 1] + prices[i - 1] - prices[i]);
        }
        return result;
    }
};