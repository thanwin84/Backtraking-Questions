//time: O(2^n)
class Solution {
public:
    vector<vector<string>> output;
    bool is_safe(vector<string> &board, int row, int col) {
        int r = row;
        int c = col;
        //upward left diagonal
        while (r >= 0 and c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }
        //upward right diagonal
        r = row;
        c = col;
        while (r >= 0 and c < board.size()) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c++;
        }
        r = row;
        c = col;
        while (r >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
        }
        return true;
    }
    bool solve(vector<string>& board, int row, int current_q, int total_q) {
        if (current_q == total_q) {
            output.push_back(board);
            return true;
        }
        for (int col = 0; col < total_q; col++) {
            if (is_safe(board, row, col)) {
                //do
                board[row][col] = 'Q';
                //recurse
                solve(board, row + 1, current_q + 1, total_q);
                //undo
                board[row][col] = '.';
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0, 0, n);
        return output;
    }
};
