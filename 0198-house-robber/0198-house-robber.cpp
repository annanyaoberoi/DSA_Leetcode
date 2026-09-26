class Solution {
public:
    int houserob(int indx, vector<int> &nums, vector<int> &dp) {
        if (indx == 0) return nums[indx];
        if (indx < 0) return 0;
        if (dp[indx] != -1) return dp[indx];
        int pick = nums[indx] + houserob(indx - 2, nums, dp);
        int notpick = 0 + houserob(indx - 1, nums, dp);
        return dp[indx] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return houserob(n - 1, nums, dp);
    }
};