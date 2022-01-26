class Solution {
public:
    bool is_valid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) {
                return false;
            }
            if (board[i][col] == c) {
                return false;
            }
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c) {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int row, int col) {
        if (row == 8 and col == 9) {
            return true;
        }
        if (col == 9) {
            row += 1;
            col = 0;
        }
        if (board[row][col] == '.') {
            for (char c = '1'; c <= '9'; c++) {
                if (is_valid(board, row, col, c)) {
                    board[row][col] = c;
                    if (solve(board, row, col + 1)) {
                        return true;
                    }
                    else {
                        board[row][col] = '.';
                    }
                }
            }
            return false;
        }
        else {
            return solve(board, row, col + 1);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
