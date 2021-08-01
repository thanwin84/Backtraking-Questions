//time: O(2^n)
class Solution {
public:
	vector<vector<string>> result;
	bool isSafe(vector<string> &board, int row, int col, int n) {
		int r = row;
		int c = col;
		while (0 <= r) {
			if (board[r][c] == 'Q') {
				return false;
			}
			r--;
		}
		r = row;
		c = col;
		while (r >= 0 and c >= 0) {
			if (board[r][c] == 'Q') {
				return false;
			}
			r--;
			c--;
		}
		r = row;
		c = col;
		while (r >= 0 and c < n) {
			if (board[r][c] == 'Q') {
				return false;
			}
			r--;
			c++;
		}
		return true;
	}
	bool solve(vector<string> &board, int x,  int qpsf, int totalQ) {
		if (totalQ == qpsf) {
			result.push_back(board);
			return true;
		}
		for (int col = 0; col < totalQ; col++) {
			if (isSafe(board, x, col, totalQ)) {
				board[x][col] = 'Q';
				solve(board, x + 1, qpsf + 1, totalQ);
				board[x][col] = '.';
			}
		}
		return false;
	}
	vector<vector<string>> solveNQueens(int n) {
		vector<string> board(n, string(n, '.'));
		solve(board, 0, 0, n);
		return result;

	}
};
