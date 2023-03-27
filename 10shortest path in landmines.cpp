//time: O(4^n*m)
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<unordered_map>
#include<string>
#include<cmath>
#include<string>
using namespace std;


void printBoard(vector<vector<int>>& board) {
	for (auto i : board) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}
// mark unsafe
// check if a cell is safe to visit
// solve the problem

class Solution {
	vector<vector<int>> moves = { {-1, 0}, { 0, 1}, {1, 0}, {0, -1} };
	int _min;
	void mark_unsafe(vector<vector<int>>& board) {
		// mark -1 to adjacent cells of a unsafe cell
		int rows = board.size();
		int cols = board[0].size();
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				if (board[row][col] == 0) {
					// up
					if (row - 1 >= 0) board[row - 1][col] = -1;
					//down
					if (row + 1 < rows) board[row + 1][col] = -1;
					// left
					if (col - 1 >= 0) board[row][col - 1] = -1;
					// right
					if (col + 1 < cols) board[row][col + 1] = -1;
				}
			}
		}
	}
	bool isSafe(vector<vector<int>>& board, vector<vector<int>>& seen, int r, int c) {
		int rows = board.size();
		int cols = board[0].size();
		if (r >= 0 && r < rows && c >= 0 && c < cols && board[r][c] == 1 && !seen[r][c]) {
			return true;
		}
		return false;
	}
	bool solve(vector<vector<int>>& board, vector<vector<int>>& seen, int row, int col, int count) {
		int rows = board.size();
		int cols = board[0].size();
		// we've react at the alst column
		if (col == cols - 1) {
			_min = min(_min, count);
			return true;
		}
		// we've already got shortest path, so we can't avoid this path
		if (count > _min) {
			return false;
		}
		// try all possible ways
		for (int move = 0; move < 4; move++) {
			int nextRow = row + moves[move][0];
			int nextCol = col + moves[move][1];
			if (isSafe(board, seen, nextRow, nextCol)) {
				seen[row][col] = 1;
				solve(board, seen, nextRow, nextCol, count + 1);
				seen[row][col] = 0;
			}
		}

	}
public:
	int findShortestPath(vector<vector<int>>& board) {
		int rows = board.size();
		int cols = board[0].size();
		_min = INT_MAX;
		// mark 1 if we  visited a cell
		vector<vector<int>> seen(rows, vector<int>(cols, 0));
        // mark unsafe to all adjacent cells of an unsafe call
		mark_unsafe(board);
		for (int i = 0; i < rows; i++) {
			if (board[i][0] != 0 && board[i][0] != -1) {
				solve(board, seen, i, 0, 0);
			}
		}
		return _min;
	}
};

int main() {

	// not safe: 0, safe = 1
	vector<vector<int>> board = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
	};
	Solution obj;
	cout << obj.findShortestPath(board);
	
	
	return 0;
}
