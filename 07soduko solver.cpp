class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for (int i = 0; i < 9; i++){
            // check entire col
            if (board[row][i] == ch) return false;
            // check entire row
            if (board[i][col] == ch) return false;
            // in each 3 * 3 matrix
            int r = 3 * (row / 3) + (i / 3);
            int c = 3 * (col / 3) + (i % 3);
            if (board[r][c] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int row, int col){
        // we've got a solution
        if (row == 8 && col == 9){
            return true;
        }
        // go to next row
        if (col == 9){
            row++;
            col = 0; 
        }
        if (board[row][col] == '.'){
            for (char ch = '1'; ch <= '9'; ch++){
                if(isValid(board, row, col, ch)){
                    // do
                    board[row][col] = ch;
                    if (solve(board, row, col + 1)){
                        return true;
                    }
                    // undo
                    board[row][col] = '.';
                }
            }
            return false;
        }
        // go to next col
        else {
            return solve(board, row, col + 1);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
