import numpy as np
def helper(board, x_move, y_move, n, counter):
    print(np.array(board))
    if counter == n * n:
        return True
    if x_move < 0 or x_move >= n or y_move < 0 or y_move >= n or board[x_move][y_move] != -1:
        return False
    x_li = [-2, -2, 1, -1, 2, 2, -1, 1]
    y_li = [-1, 1, 2, 2, 1, -1, -2, -2]
    board[x_move][y_move] = counter
    for x, y in zip(x_li, y_li):
        if helper(board,x_move + x, y_move + y, n, counter + 1 ):
            return True
    board[x_move][y_move] = -1
    return False



def knight_tour(n):
    board = [[-1 for i in range(n)]for i in range(n)]
    helper(board, 0, 0, n, 0)
    print(np.array(board))


knight_tour(6)
