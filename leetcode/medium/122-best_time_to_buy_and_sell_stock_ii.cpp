class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int left = 0;
        int right = 1;

        while (right < prices.size()) {
            int previous_profit = prices[right - 1] - prices[left];
            int current_profit = prices[right] - prices[left];
            if (current_profit < previous_profit) {
                profit += previous_profit;
                left = right;
            } else if (right == prices.size() - 1 && current_profit > 0) {
                profit += current_profit;
            }
            right++;
        }
        return profit;
    }
};
