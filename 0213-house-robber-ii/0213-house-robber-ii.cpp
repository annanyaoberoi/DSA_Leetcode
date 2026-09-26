class Solution {
public:
    int robbery(int indx, vector<int> &nums, vector<int> &dp) {
        if (indx == 0) return nums[0];
        if (indx < 0) return 0;
        if (dp[indx] != -1) return dp[indx];
        int pick = nums[indx] + robbery(indx - 2, nums, dp);
        int notpick = 0 + robbery(indx - 1, nums, dp);
        return dp[indx] = max(pick, notpick); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n == 1) return nums[0];
        vector<int> dp(n, -1);
        vector<int> temp1;
        vector<int> temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(nums[i]);
            if (i != n - 1) temp2.push_back(nums[i]);
        }
        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);
         return max(robbery(temp1.size() - 1, temp1, dp1), robbery(temp2.size() - 1, temp2, dp2));
    }
};