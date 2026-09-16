class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int bestbuy = prices[0];
        int maxprofit = INT_MIN;
        for (int i = 0; i < n; i++) {
            int profit = prices[i] - bestbuy;
            bestbuy = min(bestbuy, prices[i]);
            maxprofit = max(profit, maxprofit);
        }return maxprofit;
    }
};