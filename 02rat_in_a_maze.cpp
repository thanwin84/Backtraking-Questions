class Solution {
public:
    vector<string> output;
    bool solve(vector<vector<int>> &m, vector<vector<int>> &visited, int r, int c, int row, int col, string move) {
        if (row == r- 1 and col == c - 1) {
            output.push_back(move);
            return true;
        }
        //checking downward
        if (row + 1 < r and visited[row + 1][col] != 1 and m[row + 1][col] == 1) {
            visited[row][col] = 1;
            solve(m, visited, r, c, row + 1, col, move + 'D');
            visited[row][col] = 0;
        }
        //going left
        if (col - 1 >= 0 and visited[row][col - 1] != 1 and m[row][col - 1] == 1) {
            visited[row][col] = 1;
            solve(m, visited, r, c, row, col - 1, move + 'L');
            visited[row][col] = 0;
        }
        //going right
        if (col + 1 < c and visited[row][col + 1] != 1 and m[row][col + 1] == 1) {
            visited[row][col] = 1;
            solve(m, visited, r, c, row, col + 1, move + 'R');
            visited[row][col] = 0;
        }
        //checking upward
        if (row - 1 >= 0 and visited[row - 1][col] != 1 and m[row - 1][col] == 1) {
            visited[row][col] = 1;
            solve(m, visited, r, c, row - 1, col, move + 'U');
            visited[row][col] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>>& m, int n) {
        // Your code goes here
        int r = m.size();
        int c = m[0].size();
        if (m[0][0] == 0){
            return output;
        }
        vector<vector<int>> visited(r, vector<int>(c, 0));
        solve(m, visited, r, c, 0, 0, "");
        return output;
    }
};
