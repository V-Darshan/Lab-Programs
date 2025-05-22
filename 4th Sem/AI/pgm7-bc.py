# Backward Chaining

facts = {"fever", "cough"}
rules = {
    "flu": {"fever", "cough"},
    "cold": {"sore_throat"},
    "allergy": {"sneezing", "runny_nose"}
}
def backward_chain(goal, facts, rules, visited=None):
    if visited is None:
        visited = set()
    if goal in visited:
        return False
    if goal in facts:
        return True
    visited.add(goal)
    if goal in rules:
        conditions = rules[goal]
        for condition in conditions:
            if not backward_chain(condition, facts, rules, visited):
                return False
        return True 
    return False  
goal = "flu"
result = backward_chain(goal, facts, rules)
print(f"\nCan we infer '{goal}'? {'Yes' if result else 'No'}")

# OUTPUT:
# Can we infer 'flu'? Yes