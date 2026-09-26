class Solution {
public:
    int find(int indx, vector<int>&dp) {
        if(indx <= 1) return 1;
        if (dp[indx] != -1) return dp[indx];
        return dp[indx] = find(indx - 1, dp) + find(indx - 2, dp);
    }
    int climbStairs(int n) {
        // 1. declare
        // 2. store
        // 3. check
        vector<int> dp(n + 1, -1);
        return find(n, dp);
    }
};