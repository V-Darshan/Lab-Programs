import heapq

class Node:
    def __init__(self, name, parent=None, g=0, h=0):
        self.name = name  # Node name (or position)
        self.parent = parent  # Parent node
        self.g = g  # Cost to reach this node
        self.h = h  # Estimated cost to goal (heuristic)
        self.f = g + h  # Total cost (g + h)

    def __lt__(self, other):
        return self.f < other.f

class AStar:
    def __init__(self, graph, start, goal, heuristic):
        self.graph = graph  # Graph representation (dict of nodes and edges)
        self.start = start  # Start node
        self.goal = goal  # Goal node
        self.heuristic = heuristic  # Heuristic function

    def reconstruct_path(self, node):
        path = []
        while node:
            path.append(node.name)
            node = node.parent
        return path[::-1]  # Reverse to get the path from start to goal

    def search(self):
        open_list = []
        closed_list = set()

        # Start node setup
        start_node = Node(self.start, g=0, h=self.heuristic(self.start))
        heapq.heappush(open_list, start_node)
        
        while open_list:
            # Get node with the lowest f value
            current_node = heapq.heappop(open_list)
            
            if current_node.name == self.goal:
                # Reconstruct the path if the goal is found
                return self.reconstruct_path(current_node)
            
            closed_list.add(current_node.name)
            
            # Explore neighbors
            for neighbor, cost in self.graph.get(current_node.name, {}).items():
                if neighbor in closed_list:
                    continue
                
                g = current_node.g + cost
                h = self.heuristic(neighbor)
                neighbor_node = Node(neighbor, parent=current_node, g=g, h=h)

                # If neighbor is not in open list or found a cheaper path to it
                if not any(neighbor_node.name == n.name and neighbor_node.f >= n.f for n in open_list):
                    heapq.heappush(open_list, neighbor_node)
        
        return None  # If no path is found

# Example usage:
# Example graph (adjacency list with costs)
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

# Heuristic: straight-line distance to goal (for example purposes)
def heuristic(node):
    # In this example, assume the heuristic for each node is the estimated cost to goal 'D'
    heuristics = {'A': 6, 'B': 4, 'C': 2, 'D': 0}
    return heuristics[node]

# Initialize A* algorithm
start_node = 'A'
goal_node = 'D'
astar = AStar(graph, start_node, goal_node, heuristic)

# Perform the search
path = astar.search()
print("Path from start to goal:", path)

