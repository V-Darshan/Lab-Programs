def a_star(start, goal):
    open_set = {start}
    closed_set = set()
    g = {start: 0}
    parent = {start: None}

    while open_set:
        n = min(open_set, key=lambda x: g[x] + heuristic(x))

        if n == goal:
            return build_path(parent, n)

        open_set.remove(n)
        closed_set.add(n)

        for neighbor, cost in graph.get(n, []):
            if neighbor in closed_set:
                continue

            new_cost = g[n] + cost
            if neighbor not in open_set or new_cost < g.get(neighbor, float('inf')):
                g[neighbor] = new_cost
                parent[neighbor] = n
                open_set.add(neighbor)

    print("Path not found!")
    return None

def build_path(parent, node):
    path = []
    while node is not None:
        path.append(node)
        node = parent[node]
    path.reverse()
    print("Path found:", path)
    return path

def heuristic(n):
    h = {'A': 11, 'B': 6, 'C': 99, 'D': 1, 'E': 7, 'G': 0}
    return h.get(n, float('inf'))

graph = {
    'A': [('B', 2), ('E', 3)],
    'B': [('C', 1), ('G', 9)],
    'C': [],
    'E': [('D', 6)],
    'D': [('G', 1)],
    'G': []
}

# Run the algorithm
a_star('A', 'G')