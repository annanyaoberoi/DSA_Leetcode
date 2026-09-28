class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = INT_MIN;
        int bestbuy = prices[0];
        for (int i = 0; i < n; i++) {
            int profit = prices[i] - bestbuy;
            bestbuy = min(bestbuy, prices[i]);
            maxprofit = max(profit, maxprofit);
        }return maxprofit;
    }
};