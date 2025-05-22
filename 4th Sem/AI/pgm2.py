def display(lM, lC, rM, rC, direction):
    print("\n" + "M " * lM + "C " * lC + f"| {direction} | " + "M " * rM + "C " * rC + "\n")

def is_valid_trip(m, c, max_people=2):
    return 0 < m + c <= max_people

def is_safe(m, c):
    return (m == 0 or m >= c)

def game_over(lM, lC, rM, rC):
    return not (is_safe(lM, lC) and is_safe(rM, rC))

def get_input():
    while True:
        try:
            m = int(input("Enter the number of Missionaries=> "))
            c = int(input("Enter the number of Cannibals=> "))
            if is_valid_trip(m, c):
                return m, c
            print("Invalid move. Max 2 people, at least 1.")
        except ValueError:
            print("Enter integers only.")

print("\n\tGame Start\nNow the task is to move all of them to right side of the river")
print('''Rules:
1. The boat can carry at most two people
2. If cannibals > missionaries on either side, missionaries get eaten
3. The boat cannot cross the river empty\n''')

lM, lC, rM, rC = 3, 3, 0, 0
moves = 0

display(lM, lC, rM, rC, "---")

while True:
    # Left to Right
    print("Left side -> Right side river travel")
    m, c = get_input()
    if m > lM or c > lC:
        print("Not enough people on the left.")
        continue
    lM, lC = lM - m, lC - c
    rM, rC = rM + m, rC + c
    moves += 1
    display(lM, lC, rM, rC, "-->")
    if game_over(lM, lC, rM, rC):
        print("Cannibals eat missionaries!\nYou lost the game.")
        break
    if rM + rC == 6:
        print("You won the game!\nTotal attempts:", moves)
        break

    # Right to Left
    print("Right side -> Left side river travel")
    m, c = get_input()
    if m > rM or c > rC:
        print("Not enough people on the right.")
        continue
    lM, lC = lM + m, lC + c
    rM, rC = rM - m, rC - c
    moves += 1
    display(lM, lC, rM, rC, "<--")
    if game_over(lM, lC, rM, rC):
        print("Cannibals eat missionaries!\nYou lost the game.")
        break