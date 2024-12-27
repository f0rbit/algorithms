class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> dp(values.size());
        dp[0] = values[0];
        int best = 0;
        for (int i = 1; i < values.size(); i++) {
            int right = values[i] - i;
            best = max(best, dp[i - 1] + right);
            int left = values[i] + i;
            dp[i] = max(dp[i - 1], left);
        }

        return best;
    }
};
