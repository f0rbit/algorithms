class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int MAX = amount + 1;
        vector<int> dp(amount + 1, MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin > i) continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};