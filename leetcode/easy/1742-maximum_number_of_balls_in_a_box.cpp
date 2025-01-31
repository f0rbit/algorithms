class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int counts[46] = {};
        int max_count = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            max_count = max(max_count, ++counts[index(i)]);
        }
        return max_count;
    }

    int index(int i) {
        int n = 0;
        while (i > 0) {
            n += i % 10;
            i = i / 10;
        }
        return n;
    }
};
