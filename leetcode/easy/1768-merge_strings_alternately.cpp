class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int w1 = word1.size();
        int w2 = word2.size();
        int n = max(w1, w2);
        string result = ""; // store the merged strings
        
        // iterate from 0 to the max word
        for (int i = 0; i < n; i++) {
            if (i < w1) result += word1[i];
            if (i < w2) result += word2[i];
        }
        
        return result;
    }
};
