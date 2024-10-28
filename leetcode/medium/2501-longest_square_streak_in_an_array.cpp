class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> unique(nums.begin(), nums.end());

        for (int start : nums) {
            int streak = 0;
            long current = start;

            while (unique.contains((int) current)) {
                streak++;
                if (current * current > 1e5) break;
                current *= current;
            }

            longest = max(longest, streak);
        }

        return longest < 2 ? -1 : longest;
    }
};
