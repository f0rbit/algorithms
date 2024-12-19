class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (remaining(board, row, col, word))
                    return true;
            }
        }
        return false;
    }

    bool remaining(vector<vector<char>>& board, int row, int col, string left) {
        char x = left[0];
        char old = board[row][col];

        if (old != x)
            return false;
        if (left.size() <= 1)
            return true;
        left.erase(left.begin());

        board[row][col] = '\0';

        if (row < board.size() - 1) {
            // check upper neighbour
            if (remaining(board, row + 1, col, left))
                return true;
        }
        if (col < board[0].size() - 1) {
            if (remaining(board, row, col + 1, left))
                return true;
        }
        if (col > 0) {
            if (remaining(board, row, col - 1, left))
                return true;
        }
        if (row > 0) {
            if (remaining(board, row - 1, col, left))
                return true;
        }

        board[row][col] = old;

        return false;
    }
};