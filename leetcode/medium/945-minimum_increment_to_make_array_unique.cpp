class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                // get the difference between nums[i] and nums[i-1]+1
                int diff = (nums[i - 1] + 1) - nums[i];
                moves += diff;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return moves;
    }
};