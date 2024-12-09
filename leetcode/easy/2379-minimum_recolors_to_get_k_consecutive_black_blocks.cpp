class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0;
        int right = 0;
        int count_w = 0;
        int ans = INT32_MAX;
        while (right < blocks.size()) {
            if (blocks[right] == 'W') count_w++;
            if (right - left + 1 == k) {
                ans = min(ans, count_w);
                if (blocks[left] == 'W') count_w--;
                left++;
            }
            right++;
        }
        return ans;
    }
};
