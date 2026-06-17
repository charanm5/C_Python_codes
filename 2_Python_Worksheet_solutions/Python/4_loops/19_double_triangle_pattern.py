n = int(input("Enter number of rows: "))

# Increasing part
for i in range(1, n + 1):
    print("*" * i)

# Decreasing part
for i in range(n - 1, 0, -1):
    print("*" * i)