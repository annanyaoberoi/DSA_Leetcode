class Solution {
public:
    int f (int indx, vector<int> &nums, vector<int> &dp) {
        if (indx == 0) return nums[indx];
        if (indx < 0) return 0;
        if (dp[indx] != -1) return dp[indx];
        int pick = nums[indx] + f(indx - 2, nums, dp);
        int notpick = 0 + f(indx - 1, nums, dp);
        return dp[indx] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return f(nums.size() - 1, nums, dp);
    }
};