//time: O(4^n*m)
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
#define mod 1000000007
using namespace std;
class Solution {
public:
    int ans = INT_MAX;
    void solve(vector<vector<int>>& board, vector<vector<int>>& visited, int row, int col, int count) {
        int r = board.size();
        int c = board[0].size();
       //we've reached at the last column
        if (col >= c - 1) {
            ans = min(ans, count);
            return;
        }
      //if we've already got the shortest path, we can skip it
        if (count > ans) {
            return;
        }
        vector<vector<int>> coordinates = { {-1, 0}, { 0, 1}, {1, 0}, {0, -1} };
        for (int i = 0; i < 4; i++) {
            int next_row = row + coordinates[i][0];
            int next_col = col + coordinates[i][1];
            if (next_row >= 0 && next_row < r && next_col >= 0 && next_col < c && visited[next_row][next_col] != -1
                && board[next_row][next_col] != -1 && board[next_row][next_col] != 0) {
                //do
                visited[row][col] = -1;
                //recurse
                solve(board, visited, next_row, next_col, count + 1);
                //undo
                visited[row][col] = 0;
            }
        }
    }
        
    int shortest_path(vector<vector<int>> &board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 0) {
                    //up
                    if (i - 1 >= 0) board[i - 1][j] = -1;
                    //down
                    if (i + 1 < row) board[i + 1][j] = -1;
                    //left
                    if (j - 1 >= 0) board[i][j - 1] = -1;
                    //right
                    if (j + 1 < col) board[i][j + 1] = -1;
                }
            }
        }
        for (int i = 0; i < row; i++) {
          //if there's a landmine, we can't start from that point
            if (board[i][0] != -1 && board[i][0] != 0) {
                solve(board, visited, i, 0, 0);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution ob;
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
    cout << ob.shortest_path(board);
    
    
    return 0;
}
