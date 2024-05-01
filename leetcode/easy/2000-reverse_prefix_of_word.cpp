class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = 0;

        while (word[index] != ch && index < word.size()) index++;
        if (index >= word.size()) return word;
        reverse(word.begin(), word.begin() + index + 1);
        return word;
    }
};
