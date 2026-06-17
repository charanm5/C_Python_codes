n = int(input("Enter Number: "))

for i in range(2,n+1):
    flag = 0
    limit = (i//2) + 1
    for j in range(2,limit):
        if(i%j == 0):
            flag = 1
            break
    if(flag == 0):
        print(i," ")