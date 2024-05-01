class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            if (max >= nums.size() - 1) return true;
            if (nums[i] == 0 && max == i) return false;
            if (i + nums[i] > max) max = i + nums[i];
        }
        return true;        
    }
};
