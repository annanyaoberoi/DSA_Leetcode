class Solution {
public:
    int find(int indx, vector<int> &dp, vector<int> &nums) {
        if (indx == 0) return nums[indx];
        if (indx < 0) return 0;
        if (dp[indx] != -1) return dp[indx];
        int pick = nums[indx] + find(indx - 2, dp, nums);
        int notpick = 0 + find(indx - 1, dp, nums);
        return dp[indx] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
       int n = nums.size();
       if (n == 1) return nums[0];
       vector<int> dp(n, -1);
       vector<int> temp1, temp2;
       for (int i = 0; i < n; i++) {
        if (i != 0) temp1.push_back(nums[i]);
        if (i != n - 1) temp2.push_back(nums[i]);
       } 
       vector<int> dp1(temp1.size(), -1);
       vector<int> dp2(temp2.size(), -1);
       return max(find(temp1.size() - 1,dp1, temp1), find(temp2.size() - 1, dp2, temp2));
    }
};