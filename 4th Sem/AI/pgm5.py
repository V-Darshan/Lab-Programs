N = 8

def print_solution(board):
    for row in board:
        print(' '.join('Q' if x else '.' for x in row))

def is_safe(board, row, col):
    for i in range(col):
        if board[row][i]:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False
    for i, j in zip(range(row, N), range(col, -1, -1)):
        if board[i][j]:
            return False
    return True

def solve(col, board):
    if col >= N:
        return True
    for i in range(N):
        if is_safe(board, i, col):
            board[i][col] = 1
            if solve(col + 1, board):
                return True
            board[i][col] = 0
    return False

def solve_nq():
    board = [[0] * N for _ in range(N)]
    if not solve(0, board):
        print("Solution does not exist")
    else:
        print_solution(board)

solve_nq()
