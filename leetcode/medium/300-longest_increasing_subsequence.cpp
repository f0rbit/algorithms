class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

/* Initial recurisve/brute force solution - time limit exceeded
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums, 0, 0, 0);

    }

    int helper(vector<int>& nums, int index, int length, int previous) {
        if (index == nums.size()) return length;

        // take or skip, take longest
        int take = -1;
        if (nums[index] > previous) {
            take = helper(nums, index + 1, length + 1, nums[index]);
        } else {
            take = helper(nums, index + 1, 1, nums[index]);
        }

        int skip = helper(nums, index + 1, length, previous);

        return max(take, skip);
    }

};
*/