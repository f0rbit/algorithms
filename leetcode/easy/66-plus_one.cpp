class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int n = digits[i] + (carry ? 1 : 0);
            carry = n / 10 > 0;
            digits[i] = n % 10;
            if (!carry) break;
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};
