class Solution {
public:
    const int MOD = 1e9 + 7;

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[n][target] = 1;
        for (int d = n - 1; d >= 0; --d) {
            for (int c = 0; c <= target; ++c) {
                int ways = 0;
                for (int i = 1; i <= min(k, target - c); ++i) {
                    ways = (ways + dp[d + 1][c + i]) % MOD;
                }
                dp[d][c] = ways;
            }
        }

        return dp[0][0];
    }
};
