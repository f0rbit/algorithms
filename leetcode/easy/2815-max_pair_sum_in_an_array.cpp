class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> digit(nums.size(), 0);
        for (int i = 0; i < n; i++) {
            digit[i] = largest_digit(nums[i]);
        }

        int largest_sum = -1;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (digit[i] != digit[j]) continue;
                if (nums[i] + nums[j] > largest_sum) largest_sum = nums[i] + nums[j];
            }
        }
        return largest_sum;
    }

    int largest_digit(int i) {
        int l = 0;
        while (i > 0) {
            l = max(l, i % 10);
            i /= 10;
        }
        return l;
    }
};
