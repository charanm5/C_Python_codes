num = int(input("Enter a number: "))

sum_div = 0

i = 1
while i < num:
    if num % i == 0:
        sum_div += i
    i += 1

if sum_div == num:
    print("Perfect Number")
else:
    print("Not a Perfect Number")