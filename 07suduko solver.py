class Solution:
    def solveSudoku(self, board):
        self.solve(board)
        return board

    def is_valid(self, board, row, col, char):
        for i in range(0, 9):
          # checking the entire row
            if board[row][i] == char:
                return False
             # checking entire col
            if board[i][col] == char:
                return False
              # checking 3 * 3 board
            if board[3 * (row // 3) + i // 3][3 * (col//3) + i % 3] == char:
                return False
        return True
    def solve(self, board):
        for i in range(len(board)):
            for j in range(len(board)):
                if board[i][j] == '.':
                    for c in range(1, 10):
                        if self.is_valid(board, i, j, str(c)):
                            board[i][j] = str(c)
                            if self.solve(board):
                                return True
                            else:
                                board[i][j] = '.'
                    return False
        return True
# short version
class Solution:
    def solveSudoku(self, board):
        self.solve(board, 0, 0)
        

    def is_valid(self, board, row, col, char):
        for i in range(0, 9):
            if board[row][i] == char:
                return False
            if board[i][col] == char:
                return False
            if board[3 * (row // 3) + i // 3][3 * (col//3) + i % 3] == char:
                return False
        return True
    def solve(self, board, row, col):
        if col == len(board) and row < 9:
            col = 0
            row += 1
            if row == len(board):
                return True
            
        if board[row][col] == '.':
            for i in range(1, 10):
                if self.is_valid(board, row, col, str(i)):
                    board[row][col] = str(i)
                    if self.solve(board, row, col + 1):
                        return True
                    else:
                        board[row][col] = '.'
            return False
        else:
            return self.solve(board, row, col + 1)

