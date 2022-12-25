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
    def __init__(self):
        self.result = []
        self.x_coordinates = [1, 0, 0, -1]
        self.y_coordinates = [0, -1, 1, 0]
        
    def findPath(self, m, n):
        # to keep track of visited cell, because we can't visit a cell twice
        visited = [[0 for i in range(n)]for j in range(n)]
        if m[0][0] == 0:
            return self.result
        self.solve(m, n, visited, 0, 0, "")
        return self.result

    def solve(self, m, n, visited, curr_row, curr_col, move):
        # we are at the destination
        if curr_row == n - 1 and curr_col == n - 1:
            self.result.append(move)
            return
        # downward
        ways = 'DLRU'
        for ind in range(4):
            next_row = curr_row + self.x_coordinates[ind]
            next_col = curr_col + self.y_coordinates[ind]
            if 0 <= next_row < n and 0 <= next_col < n and visited[next_row][next_col] != 1 and m[next_row][next_col] == 1:
                # do
                visited[curr_row][curr_col] = 1
                # recurse
                self.solve(m, n, visited, next_row, next_col, move + ways[ind])
                # undo
                visited[curr_row][curr_col] = 0
                
