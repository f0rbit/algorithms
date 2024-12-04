class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1); // dp[i] will store all valid combinations for i pairs of parentheses
        dp[0] = { "" }; // Base case: one combination for 0 pairs

        for (int i = 1; i <= n; ++i) {
            for (int l = 0; l < i; ++l) {
                for (const string& left : dp[l]) {
                    for (const string& right : dp[i - 1 - l]) {
                        dp[i].push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        return dp[n];
    }
};
