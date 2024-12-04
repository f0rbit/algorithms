class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;
        for (int x = 0; x < matrix.size(); x++) {
            for (int y = 0; y < matrix[0].size(); y++) {
                if (matrix[x][y] == 0) {
                    rows.insert(x);
                    cols.insert(y);
                }
            }
        }

        for (int x = 0; x < matrix.size(); x++) {
            for (int y = 0; y < matrix[0].size(); y++) {
                if (matrix[x][y] == 0) continue;
                if (rows.contains(x)) matrix[x][y] = 0;
                if (cols.contains(y)) matrix[x][y] = 0;
            }
        }
    }
};
