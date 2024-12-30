class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;

        // floor(n/5) == zero's, but > 25, we get an extra one, and 125, etc...
        for (int i = 5; n / i >= 1; i *= 5) {
            count += n / i;
        }

        return count;
    }
};
