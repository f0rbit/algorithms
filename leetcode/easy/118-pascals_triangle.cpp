class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> table(numRows);
        table[0] = {1};
        for (int i = 1; i < numRows; i++) {
            table[i].push_back(1);
            for (int j = 1; j < i; j++) {
                table[i].push_back(table[i-1][j - 1] + table[i-1][j]);
            }
            table[i].push_back(1);
        }
        return table;
    }
};
