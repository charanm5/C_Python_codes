fruits = ["apple", "banana", "cherry", "kiwi", "mango"]

print([f for f in fruits if "a" in f])
print([f.upper() for f in fruits])
print(["orange" if f == "banana" else f for f in fruits])