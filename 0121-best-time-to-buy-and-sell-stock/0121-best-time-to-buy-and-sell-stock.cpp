class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int bestbuy = nums[0];
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int profit = nums[i] - bestbuy;
            bestbuy = min(bestbuy, nums[i]);
            maxi = max(profit, maxi);
        }return maxi;
    }
};