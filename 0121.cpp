class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minDay = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minDay);
            minDay = min(minDay, prices[i]);
        }
        return maxProfit;
    }
};
