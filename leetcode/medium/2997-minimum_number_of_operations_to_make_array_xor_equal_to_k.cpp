class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int initial = 0;
        for (int i : nums) {
            initial ^= i;
        }

        int value = (initial ^ k);
        int counter = 0;
        while (value) {
            counter++;
            value = value & (value - 1);
        }
        return counter;
    }
};
