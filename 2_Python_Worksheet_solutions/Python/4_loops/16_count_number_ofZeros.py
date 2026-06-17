num = int(input("Enter an integer: "))

count = 0
temp = abs(num)

if temp == 0:
    count = 1
else:
    while temp > 0:
        if temp % 10 == 0:
            count += 1
        temp = temp // 10

print("Number of 0s:", count)