num = int(input("Enter a number: "))

while num >= 10:
    temp = num
    total = 0

    while temp > 0:
        digit = temp % 10
        total += digit
        temp = temp // 10

    num = total

print("Result:", num)