class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }

    int helper(vector<int>& nums, int index, int curr) {
        if (index == nums.size()) return curr;

        int with = helper(nums, index + 1, curr ^ nums[index]);
        int without = helper(nums, index + 1, curr);

        return with + without;
    }
};