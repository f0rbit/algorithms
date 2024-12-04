class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> letters;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) letters.push(s[i]);
        }

        string res;
        res.resize(s.size());

        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                res[i] = letters.top();
                letters.pop();
            } else {
                res[i] = s[i];
            }
        }

        return res;
    }
};
