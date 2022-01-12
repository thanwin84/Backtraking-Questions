class Solution:
    def __init__(self):
        self.output = []
    def isSafe(self, board, roww, coll):
        n = len(board) - 1
        row = roww
        col = coll
        # checking upward
        while 0 <= row:
            if board[row][col] == 1:
                return False
            row -= 1
        row = roww
        col = coll
        # checking diagonally upward to the left
        while row >= 0 and col >= 0:
            if board[row][col] == 1:
                return False
            row -= 1
            col -= 1
        row = roww
        col = coll
        # checking diagonally upward to the right
        while row >= 0 and col <= n:
            if board[row][col] == 1:
                return False
            row -= 1
            col += 1
        return True
    def solve(self, board, row, col, qpsf, totalQ, result):
        if totalQ == qpsf:
            self.output.append(result)
            return
        for col in range(len(board)):
            if self.isSafe(board, row, col):
                # do
                board[row][col] = 1
                tmp = "." * len(board)
                # recurse
                self.solve(board, row + 1, col, qpsf + 1, totalQ, result +[tmp[:col]+"Q"+tmp[col+1:]])
                # undo
                board[row][col] = 0
        return False

    def solveNQueens(self, n):
        board = [[0 for i in range(n)]for j in range(n)]
        self.solve(board, 0, 0, 0, n, [])
        return self.output
