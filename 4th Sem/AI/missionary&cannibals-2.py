from collections import deque

# Define the state as a tuple (left_missionaries, left_cannibals, boat_position)
# boat_position: 0 = left, 1 = right

class MissionariesCannibals:
    def __init__(self, missionaries=3, cannibals=3):
        self.missionaries = missionaries
        self.cannibals = cannibals
        self.initial_state = (missionaries, cannibals, 0)  # Start with all on the left side (boat is also on the left)
        self.goal_state = (0, 0, 1)  # Goal state: all are on the right side (boat is also on the right)

    # Check if the state is valid (no side has more cannibals than missionaries, unless there are no missionaries)
    def is_valid(self, state):
        left_m, left_c, boat = state
        right_m = self.missionaries - left_m
        right_c = self.cannibals - left_c

        # Rule: Number of cannibals cannot exceed number of missionaries on either side
        if left_m < left_c and left_m > 0:
            return False
        if right_m < right_c and right_m > 0:
            return False
        return True

    # Generate possible actions (moves)
    def get_neighbors(self, state):
        left_m, left_c, boat = state
        neighbors = []
        
        # If the boat is on the left side
        if boat == 0:
            directions = [(1, 0), (0, 1), (1, 1), (2, 0), (0, 2)]  # Moves: (1 missionary, 0 cannibals), etc.
            for m, c in directions:
                new_state = (left_m - m, left_c - c, 1)  # Boat moves to the right side
                if new_state[0] >= 0 and new_state[1] >= 0 and self.is_valid(new_state):
                    neighbors.append(new_state)
        
        # If the boat is on the right side
        else:
            directions = [(1, 0), (0, 1), (1, 1), (2, 0), (0, 2)]  # Same possible moves as above
            for m, c in directions:
                new_state = (left_m + m, left_c + c, 0)  # Boat moves to the left side
                if new_state[0] <= self.missionaries and new_state[1] <= self.cannibals and self.is_valid(new_state):
                    neighbors.append(new_state)
        
        return neighbors

    # Heuristic: Number of people left on the start side (more people left means higher cost)
    def heuristic(self, state):
        left_m, left_c, _ = state
        return left_m + left_c  # More people left means higher heuristic (worse state)

    # Best First Search algorithm
    def best_first_search(self):
        open_list = []
        closed_list = set()

        # Push the initial state into the open list with its heuristic value
        open_list.append((self.heuristic(self.initial_state), self.initial_state, []))

        while open_list:
            # Sort the open list based on the heuristic value (focusing on lowest first)
            open_list.sort(key=lambda x: x[0])
            _, current_state, path = open_list.pop(0)

            # If the current state is the goal, return the path
            if current_state == self.goal_state:
                return path + [current_state]
            
            if current_state in closed_list:
                continue

            closed_list.add(current_state)

            # Expand neighbors
            for neighbor in self.get_neighbors(current_state):
                if neighbor not in closed_list:
                    open_list.append((self.heuristic(neighbor), neighbor, path + [current_state]))

        return None  # No solution found

# Initialize the problem with 3 missionaries and 3 cannibals
problem = MissionariesCannibals()

# Perform Best First Search to find a solution path
solution = problem.best_first_search()

# Print the solution path
if solution:
    print("Solution Path:")
    for step in solution:
        print(step)
else:
    print("No solution found")

