num = int(input("Enter a number: "))

i = 2

while i <= num:
    if num % i == 0:
        print("Smallest divisor:", i)
        break
    i += 1