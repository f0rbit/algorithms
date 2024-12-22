class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;

        int original = image[sr][sc];
        if (original == color) return image; // this line avoids memory overflow

        q.push(make_pair(sr, sc));

        while (!q.empty()) {
            pair<int, int> pos = q.front();
            q.pop();
            int row = pos.first;
            int col = pos.second;

            if (image[row][col] != original) continue;

            image[row][col] = color;

            // visit the neighbours
            if (row > 0) q.push(make_pair(row - 1, col));
            if (col > 0) q.push(make_pair(row, col - 1));
            if (row < image.size() - 1) q.push(make_pair(row + 1, col));
            if (col < image[0].size() - 1) q.push(make_pair(row, col + 1));            
        }

        return image;
    }
};