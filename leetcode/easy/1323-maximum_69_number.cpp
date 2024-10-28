class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        int longest = num;

        for (int i = 0; i < str.size(); i++) {
            string copy = str;
            if (str.at(i) == '6') {
                copy[i] = '9';
            } else {
                copy[i] = '6';
            }
            int res = stoi(copy);
            if (res > longest) longest = res;
        }
        return longest;
    }
};
