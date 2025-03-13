# Tic-Tac-Toe Game in Python

# Function to print the current board
def print_board(board):
    for row in range(3):
        print(" | ".join(board[row]))
        if row < 2:
            print("--------")
            
# Function to check for a winner
def check_winner(board, player):
    # Check rows, columns, and diagonals
    for i in range(3):
        if all([cell == player for cell in board[i]]):  # check row
            return True
        if all([board[j][i] == player for j in range(3)]):  # check column
            return True
    # Check diagonals
    if board[0][0] == player and board[1][1] == player and board[2][2] == player:
        return True
    if board[0][2] == player and board[1][1] == player and board[2][0] == player:
        return True
    return False

# Function to check if the board is full (a tie)
def is_full(board):
    for row in board:
        if " " in row:
            return False
    return True

# Main game function
def play_game():
    board = [[" " for _ in range(3)] for _ in range(3)]  # Initialize an empty board
    current_player = "X"  # Player X always starts
    
    while True:
        print_board(board)  # Display the board
        print(f"Player {current_player}'s turn:")
        
        # Get valid input from the current player
        while True:
            try:
                row, col = map(int, input("Enter row and column (0, 1, 2) separated by a space: ").split())
                if board[row][col] == " ":
                    board[row][col] = current_player
                    break
                else:
                    print("That cell is already taken. Please choose a different cell.")
            except (ValueError, IndexError):
                print("Invalid input. Please enter row and column values between 0 and 2.")
        
        # Check if the current player has won
        if check_winner(board, current_player):
            print_board(board)
            print(f"Player {current_player} wins!")
            break
        
        # Check if it's a tie
        if is_full(board):
            print_board(board)
            print("It's a tie!")
            break
        
        # Switch players
        current_player = "O" if current_player == "X" else "X"

# Start the game
if __name__ == "__main__":
    play_game()