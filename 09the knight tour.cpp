//time: O(8^N^2)
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
    bool solve(vector<vector<int>>& board, int row, int col, int counter, int n) {
        //we've covered all the cell
        if (counter == n * n) {
            cout << counter << endl;
            return true;
        }
        if (row < 0 or row >= n or col < 0 or col >= n or board[row][col] != -1) {
            return false;
        }
        vector<vector<int>> coordinates = { {-2, -1}, {-2, 1}, {-1, 2}, {1, 2 }, {2, 1}, {2, -1}, {1, -2}, {-1, -2} };
        //do
        board[row][col] = counter;
        //recurse
        for (int i = 0; i < coordinates.size(); i++) {
            int next_row = row + coordinates[i][0];
            int next_col = col + coordinates[i][1];
            if (solve(board, next_row, next_col, counter + 1, n)) {
                return true;
            }
        }
        //undo
        board[row][col] = -1;
        return false;

    }
    void knight_tour(int n) {
        vector<vector<int>> board(n, vector<int>(n, -1));
        solve(board, 0, 0, 0, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution ob;
    ob.knight_tour(6);
    
    
    return 0;
}
