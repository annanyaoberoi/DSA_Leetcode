class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int bestbuy=prices[0];
        int max_profit=0;
        for(int i=0;i<n;i++){
            int profit=prices[i]-bestbuy;
            max_profit=max(max_profit,profit);
            bestbuy=min(bestbuy,prices[i]);
        }return max_profit;
    }
};