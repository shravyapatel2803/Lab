import numpy as np
import random

def is_safe(board, row, col, n):
    for i in range(col):
        if board[row][i] == 1:
            return False
    
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    return True

def solve_n_queens(board, col, n):
    if col >= n:
        return True
    
    rows = list(range(n))
    random.shuffle(rows)
    
    for i in rows:
        if is_safe(board, i, col, n):
            board[i][col] = 1
            if solve_n_queens(board, col + 1, n):
                return True
            board[i][col] = 0
    
    return False

def generate_n_queens(n=8):
    board = np.zeros((n, n), dtype=int)
    
    if solve_n_queens(board, 0, n):
        return board
    else:
        return None

def print_board(board):
    if board is None:
        print("No solution found")
        return
    
    for row in board:
        print(" ".join("Q" if cell == 1 else "." for cell in row))
    
if __name__ == "__main__":
    n = 8  # Change n for different board sizes
    board = generate_n_queens(n)
    print_board(board)
