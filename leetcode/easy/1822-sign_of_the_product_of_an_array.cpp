class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool sign = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) return 0;
            if (nums[i] < 0) sign = !sign;
        }
        return sign ? -1 : 1;
    }
};
