class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        int i = 0;
        // ignore starting whitespace
        while (s[i] == ' ') i++;
        int start = i;
        int end = i;
        int n = s.size();

        while (end < n) {
            while (end < n && s[end] != ' ') end++;
            words.push(s.substr(start, end - start));
            // go to start of next word
            start = end;
            while (start < n && s[start] == ' ') start++;
            if (start >= n) break;
            end = start;
        }

        // construct reversed string
        string res = "";
        while (!words.empty()) {
            if (res.size() != 0) res += " ";
            res += words.top();
            words.pop();
        }

        return res;
    }
};
