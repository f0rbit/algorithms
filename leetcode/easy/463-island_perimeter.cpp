class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (grid[x][y] == 0) continue;
                if (x == 0) {
                    sum++;
                } else if (grid[x-1][y] == 0) {
                    sum++;
                }
                if (y == 0) {
                    sum++;
                } else if (grid[x][y - 1] == 0) {
                    sum++;
                }
                if (x == n - 1) {
                    sum++;
                } else if (grid[x + 1][y] == 0) {
                    sum++;
                }
                if (y == m - 1) {
                    sum++;
                } else if (grid[x][y + 1] == 0) {
                    sum++;
                }
            }
        }
        return sum;
    }
};
