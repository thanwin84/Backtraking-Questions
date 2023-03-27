//time: O(8^N^2)
class Solution {
	vector<int> move_x;
	vector<int> move_y;
	bool isSafe(vector<vector<int>>& board, int row, int col) {
		int n = board.size();
		if (row >= 0 && row < n && col >= 0 && col < n && board[row][col] == -1) {
			return true;
		}
		return false;
	}
	bool solve(vector<vector<int>>& board, int row, int col, int currentPosition) {
		int n = board.size();
		board[row][col] = currentPosition;
		if (currentPosition == (n * n)) {
			return true;
		}
        // try all possible ways
		for (int move = 0; move < move_x.size(); move++) {
			int next_row = row + move_x[move];
			int next_col = col + move_y[move];
			if (isSafe(board, next_row, next_col)) {
				if (solve(board, next_row, next_col, currentPosition + 1)) {
					return true;
				}
			}
		}
		board[row][col] = -1;
		return false;

	}
public:
	void knightTours(int n) {
		move_x = { 2, 1, -1, -2, -2, -1, 1, 2 };
		move_y = { 1, 2, 2, 1, -1, -2, -2, -1 };
		vector<vector<int>> board(n, vector<int>(n, -1));
		solve(board, 0, 0, 1);
		printBoard(board);
		
	}
};
