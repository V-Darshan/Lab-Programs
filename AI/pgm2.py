def print_board(board):
    for row in range(3):
        print("|".join(board[row]))
        if row<2:
            print("---------")

def check_winner(board,player):
    for i in range(3):
        if all([cell==player for cell in board[i]]):
            return True
        if all([board[j][i]==player for j in range(3)]):
            return True
        if board[0][0]==player and board[1][1]==player and board[2][2]==player:
            return True
        if board[0][2]==player and board[1][1]==player and board[2][0]==player:
            return False
        
def is_full(board):
    for row in board:
        if"" in row:
            return False
        return True
    
def play_gmae():
    board=[[""for _ in range(3)]for _ in range(3)]
    current_player="X"

    while True:
        print_board(board)
        print(f"Player {current_player}'s turn:")

        while True:
            try:
                row,col=map(int,input("Enter row and coloumn (0,1,2) seprated by a space:").split())
                if board[row][col]=="":
                    
            