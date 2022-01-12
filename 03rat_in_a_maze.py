# time: O(4^(n*m)) and space: O(n*m)
class Solution:
    def __init__ (self):
        self.result = []
    def findPath(self, m, n):
        visited = [[0 for i in range(n)]for j in range(n)]
        if m[0][0] == 0:
            return self.result
        self.solve(m, n, visited, 0, 0, "")
        return self.result
    def solve(self, m, n, visited, row, col, move):
        if row == n -1 and col == n -1:
            self.result.append(move)
            return
        # downward
        if row + 1 < n and visited[row + 1][col] != 1 and m[row + 1][col] == 1:
            visited[row][col] = 1
            self.solve(m, n, visited, row + 1, col, move + 'D')
            visited[row][col] = 0
        #left
        if col - 1 >= 0 and visited[row][col -1] != 1 and m[row][col -1] == 1:
            visited[row][col] = 1
            self.solve(m, n, visited, row, col - 1, move + 'L')
            visited[row][col] = 0
        # right
        if col + 1 < n and visited[row][col + 1] != 1 and m[row][col + 1] == 1:
            visited[row][col] = 1
            self.solve(m, n, visited, row, col + 1, move + 'R')
            visited[row][col] = 0
        # upward
        if row - 1 >= 0 and visited[row - 1][col] != 1 and m[row - 1][col] == 1:
            visited[row][col] = 1
            self.solve(m, n, visited, row - 1, col, move + 'U')
            visited[row][col] = 0
# short code
class Solution:
    def __init__ (self):
        self.result = []
        self.row = [1, 0, 0, -1]
        self.col = [0, -1, 1, 0]
    def findPath(self, m, n):
        visited = [[0 for i in range(n)]for j in range(n)]
        if m[0][0] == 0:
            return self.result
        self.solve(m, n, visited, 0, 0, "")
        return self.result
    def solve(self, m, n, visited, row, col, move):
        if row == n -1 and col == n -1:
            self.result.append(move)
            return
        # downward
        ways = 'DLRU'
        for ind in range(4):
            nextrow = row + self.row[ind]
            nextcol = col + self.col[ind]
            if nextrow < n and nextcol < n and nextrow >= 0  and nextcol >= 0 and visited[nextrow][nextcol] != 1 and m[nextrow][nextcol] == 1:
                # do
                visited[row][col] = 1
                # recurse
                self.solve(m, n, visited, nextrow, nextcol, move + ways[ind])
                # undo
                visited[row][col] = 0
