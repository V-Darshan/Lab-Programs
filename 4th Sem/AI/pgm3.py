def is_safe(board,row,col):
    for i in range(row):        #check the column for conflicts
        if board[i]==col or board[i]==col-row+i or board[i]==col+row-i:
            return False
    return True
def solve_queens(board,row):
    if row==len(board):         #If all queens are placed
        return True
    for col in range(len(board)):
        if is_safe(board,row,col):
            board[row]=col
            if solve_queens(board,row+1):
                return True
                board[row]=-1   #Backtrack
    return False
def print_solution(board):
    for row in board:
        line=["Q" if i==row else "." for i in range(len(board))]
        print("".join(line))
    print("\n")

def solve_8_queens():
    board=[-1]*8        #A List to store the column position of the queens in each row
    if solve_queens(board,0):
        print_solution(board)
    else:
        print("No solution found")

solve_8_queens()    #Run the solution