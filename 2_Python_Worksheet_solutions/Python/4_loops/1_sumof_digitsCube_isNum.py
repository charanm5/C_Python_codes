num = 153
temp = num
result = 0

while temp > 0:
    digit = temp%10
    result += pow(digit,3)
    temp=temp//10

if(result == num):
    print("Equal")
else:
    print("Not equal")