import numpy as np
class Solution:
    def __init__(self):
        self.min_path = float('inf')
    def shortest_path(self, mat):
        row = len(mat)
        col = len(mat[0])
        for i in range(row):
            for j in range(col):
                if mat[i][j] == 0:
                    x_li = [0, -1, 0, 1]
                    y_li = [1, 0, -1, 0]
                    for k in range(4):
                        next_r = i + x_li[k]
                        next_c = j + y_li[k]
                        if next_r < row and next_c < col and next_r >= 0 and next_c >= 0:
                            mat[next_r][next_c] = -1

        visited = [[0 for i in range(col)] for j in range(row)]
        for i in range(row):
            for j in range(col):
                if mat[i][j] == -1:
                    mat[i][j] = 0
        for i in range(row):
            if mat[i][0] ==1:
                self.solve(mat, visited, i, 0, 0)

        print(self.min_path)

    def solve(self, mat, visited, r,c , count):
        if c == len(mat[0]) -1:
            self.min_path = min(count, self.min_path)
            return
        x_li = [0, -1, 0, 1]
        y_li = [1, 0, -1, 0]
        # we can discard the path if we found better path before
        if count > self.min_path:
            return

        for i in range(4):
            next_r = r + x_li[i]
            next_c = c + y_li[i]
            if next_r < len(mat) and next_c < len(mat[0]) and next_r >= 0 and next_c >= 0 and visited[next_r][next_c] != 1 and mat[next_r][next_c] != 0:
                visited[r][c] = 1
                self.solve(mat, visited, next_r, next_c, count + 1)
                visited[r][c] = 0


mat = [
        [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
        [ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 ],
        [ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 ],
        [ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 ],
        [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
        [ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 ],
        [ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 ],
        [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
        [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
        [ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 ],
        [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
        [ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 ] ]
ob = Solution()
ob.shortest_path(mat)
