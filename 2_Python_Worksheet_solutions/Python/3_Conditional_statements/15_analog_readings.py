a = int(input("Enter first reading: "))
b = int(input("Enter second reading: "))

if abs(a - b) <= 5:
    print("Match")
else:
    print("No Match")