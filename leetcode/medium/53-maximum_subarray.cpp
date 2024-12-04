class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), { nums[0] });

        int m = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], 0) + nums[i];
            m = max(m, dp[i]);
        }

        return m;
    }
};
