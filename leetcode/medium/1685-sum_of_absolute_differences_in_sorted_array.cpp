class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // brute force approach (time limit exceeded 52/59)
        // vector<int> result(nums.size(), 0);

        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = 0; j < nums.size(); j++) {
        //         int diff = abs(nums[i] - nums[j]);
        //         result[i] += diff;
        //     }
        // }

        // return result;

        int sum = accumulate(nums.begin(), nums.end(), 0);

        int left = 0;
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int right = sum - left - nums[i];
            int left_count = i;
            int right_count = nums.size() - 1 - i;

            int left_total = left_count * nums[i] - left;
            int right_total = right - right_count * nums[i];

            ans[i] = left_total + right_total;
            left += nums[i];
        }

        return ans;
    }
};