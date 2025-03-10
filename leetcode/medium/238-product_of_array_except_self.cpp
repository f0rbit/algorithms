class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);

        int curr = 1;
        for (int i = 0; i < n; i++) {
            curr *= nums[i];
            left[i] = curr;
        }

        curr = 1;
        for (int i = n - 1; i >= 0; i--) {
            curr *= nums[i];
            right[i] = curr;
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                res[i] = right[i+1];
            } else if (i == n - 1) {
                res[i] = left[i - 1];
            } else {
                res[i] = left[i - 1] * right[i + 1];
            }
        }

        return res;
    }
};
