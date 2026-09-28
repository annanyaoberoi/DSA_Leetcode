class Solution {
public:
    int solve(int indx, vector<int> &dp, vector<int> &cost) {
        if (indx <= 1) return 0;
        if (dp[indx] != -1) return dp[indx];
        int one = solve(indx - 1, dp, cost) + cost[indx - 1];
        int two = solve(indx - 2, dp, cost) + cost[indx - 2];
        return dp[indx] = min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return solve(n, dp, cost);
    }
};