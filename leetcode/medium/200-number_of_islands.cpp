class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        short int sum = 0;
        short int n = grid.size();
        short int m = grid[0].size();
        for (short int x = 0; x < n; x++) {
            for (short int y = 0; y < m; y++) {
                if (grid[x][y] == '1') {
                    sum++;
                    visit(grid, x, y);
                }
            }
        }
        return sum;
    }

    void visit(vector<vector<char>>& grid, short int x, short int y) {
        if (grid[x][y] == '0') return;
        grid[x][y] = '0';
        if (x > 0) visit(grid, x - 1, y);
        if (x < grid.size() - 1) visit(grid, x + 1, y);
        if (y > 0) visit(grid, x, y - 1);
        if (y < grid[0].size() - 1) visit(grid, x, y + 1);
    }
};
