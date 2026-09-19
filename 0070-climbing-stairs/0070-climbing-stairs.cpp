class Solution {
public:
    int f(int indx, vector<int> &dp) {
        if (indx <= 1) return 1;
        if (dp[indx] != -1) return dp[indx];
        int left = f (indx - 1,dp);
        int right = f(indx - 2,dp);
        return dp[indx] = left + right;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};