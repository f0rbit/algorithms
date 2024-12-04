class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res = { words[0] };
        for (int i = 1; i < words.size(); i++) {
            if (groups[i] == groups[i - 1]) continue;
            res.push_back(words[i]);
        }
        return res;
    }
};
