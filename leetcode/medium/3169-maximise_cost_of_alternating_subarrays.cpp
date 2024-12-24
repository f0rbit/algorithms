class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        vector<pair<long, long>> dp(nums.size());
        dp[0] = make_pair(nums[0], nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            auto prev = dp[i - 1];
            dp[i].first = max(prev.first, prev.second) + nums[i];
            dp[i].second = prev.first - nums[i];    
        }

        auto res = dp[nums.size() - 1];
        return max(res.first, res.second);
    }
};