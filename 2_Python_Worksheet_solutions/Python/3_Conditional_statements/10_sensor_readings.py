r1 = int(input("Reading 1: "))
r2 = int(input("Reading 2: "))
r3 = int(input("Reading 3: "))

threshold = 50

high_count = (r1 > threshold) + (r2 > threshold) + (r3 > threshold)

print("Majority High" if high_count >= 2 else "Majority Low")