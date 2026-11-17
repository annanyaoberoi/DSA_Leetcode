class Solution {
public:
    int minimumChanges(string s, int k) {

        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Step 1: Precompute minimum changes
        for(int i = 0; i < n; i++) {

            for(int len = 2; i + len <= n; len++) {

                int best = INF;

                // Try every proper divisor
                for(int d = 1; d < len; d++) {

                    if(len % d != 0)
                        continue;

                    int changes = 0;

                    // Check each group
                    for(int r = 0; r < d; r++) {

                        int count = len / d;

                        int l = 0;
                        int right = count - 1;

                        while(l < right) {

                            if(s[i + r + l * d] !=
                               s[i + r + right * d]) {
                                changes++;
                            }

                            l++;
                            right--;
                        }
                    }

                    best = min(best, changes);
                }

                cost[i][i + len - 1] = best;
            }
        }

        // Step 2: DP
        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, INF)
        );

        dp[0][0] = 0;

        for(int p = 1; p <= k; p++) {

            for(int i = 2 * p; i <= n; i++) {

                for(int j = 2 * (p - 1); j <= i - 2; j++) {

                    dp[i][p] = min(
                        dp[i][p],
                        dp[j][p - 1] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};