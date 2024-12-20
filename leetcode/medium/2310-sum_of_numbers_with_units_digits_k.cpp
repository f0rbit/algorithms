class Solution {
public:
    int minimumNumbers(int num, int k) {
        vector<int> nums; // array of {9,19,29,39} if k = 9 for example
        for (int i = k; i <= num; i += 10) {
            nums.push_back(i);
        }
        return search(nums, num);
    }

    // same concept as coin change, where we pick from array at each step to make amount
    int search(vector<int>& nums, int amount) {
        int MAX = amount + 1;
        vector<int> dp(amount + 1, MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int num : nums) {
                if (num > i) continue;
                dp[i] = min(dp[i], dp[i - num] + 1);
            }
        }
        return dp[amount] == MAX ? -1 : dp[amount];
    }
};