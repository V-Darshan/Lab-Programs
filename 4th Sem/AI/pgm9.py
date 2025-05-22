theBoard = {
    'top-L': ' ', 'top-M': ' ', 'top-R': ' ',
    'mid-L': ' ', 'mid-M': ' ', 'mid-R': ' ',
    'low-L': ' ', 'low-M': ' ', 'low-R': ' '
}

def printBoard(board):
    print(board['top-L'] + ' | ' + board['top-M'] + ' | ' + board['top-R'])
    print('--+---+--')
    print(board['mid-L'] + ' | ' + board['mid-M'] + ' | ' + board['mid-R'])
    print('--+---+--')
    print(board['low-L'] + ' | ' + board['low-M'] + ' | ' + board['low-R'])

def checkWinner(board, player):
    # Check all win conditions
    return (
        (board['top-L'] == board['top-M'] == board['top-R'] == player) or
        (board['mid-L'] == board['mid-M'] == board['mid-R'] == player) or
        (board['low-L'] == board['low-M'] == board['low-R'] == player) or
        (board['top-L'] == board['mid-L'] == board['low-L'] == player) or
        (board['top-M'] == board['mid-M'] == board['low-M'] == player) or
        (board['top-R'] == board['mid-R'] == board['low-R'] == player) or
        (board['top-L'] == board['mid-M'] == board['low-R'] == player) or
        (board['top-R'] == board['mid-M'] == board['low-L'] == player)
    )

turn = 'X'
for i in range(9):
    printBoard(theBoard)
    print('Turn for ' + turn + '. Move on which space?')
    move = input()

    if move not in theBoard:
        print('Invalid position. Try again.')
        continue

    if theBoard[move] != ' ':
        print('That spot is already taken. Try again.')
        continue

    theBoard[move] = turn

    if checkWinner(theBoard, turn):
        printBoard(theBoard)
        print(turn + ' wins the game!')
        break

    # Switch turns
    if turn == 'X':
        turn = 'O'
    else:
        turn = 'X'
else:
    # If loop completes without break, it's a draw
    printBoard(theBoard)
    print("It's a draw!")
