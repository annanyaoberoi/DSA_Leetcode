class Solution {
public:
    int find(vector<int> &dp, int indx, vector<int> &cost) {
        if (indx <= 1) return 0;
        if(dp[indx] != -1) return dp[indx];
        int l = find(dp,indx - 1, cost) + cost[indx - 1];
        int r = find(dp,indx - 2, cost) + cost[indx - 2];
        return dp[indx] = min(l, r);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return find(dp, n, cost);
    }
};