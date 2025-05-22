# Forward Chaining

facts = {"fever", "cough"}
rules = [
    ({"fever", "cough"}, "flu"),
    ({"sore_throat"}, "cold"), 
    ({"sneezing", "runny_nose"}, "allergy")
]
inferred = set()
while True:
    applied = False  
    for conditions, conclusion in rules:
        if conditions.issubset(facts) and conclusion not in facts:
            facts.add(conclusion)      
            inferred.add(conclusion)
            print(f"Inferred: {conclusion}")
            applied = True            
    if not applied:
        break  
print("\nFinal Facts:", facts)
print("Inferred Facts:", inferred)

# OUTPUT:
# Inferred: flu
# Final Facts: {'cough', 'fever', 'flu'}
# Inferred Facts: {'flu'}