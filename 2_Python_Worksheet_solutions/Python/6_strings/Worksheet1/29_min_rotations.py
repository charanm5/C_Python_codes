s = "abcde"
temp = s
count = 0

while True:
    temp = temp[1:] + temp[0]
    count += 1
    if temp == s:
        break

print(count)