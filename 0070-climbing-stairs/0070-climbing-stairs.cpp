class Solution {
public:
    int solve(int indx, vector<int> &dp, int n) {
        if (indx <= 1) return 1;
        if (dp[indx] != -1) return dp[indx];
        int one = solve(indx - 1, dp, n);
        int two = solve(indx - 2, dp, n);
        return dp[indx] = one + two;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp, n);
    }
};