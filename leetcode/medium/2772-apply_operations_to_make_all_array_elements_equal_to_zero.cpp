class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int cur = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (cur > nums[i]) return false;
            nums[i] -= cur;
            cur += nums[i];
            if (i >= k - 1) {
                cur -= nums[i-k+1];
            }
        }
        return cur == 0;
    }
};
