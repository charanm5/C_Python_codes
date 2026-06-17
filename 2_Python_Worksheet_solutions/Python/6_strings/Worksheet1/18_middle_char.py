s = "python"
mid = len(s)//2

if len(s) % 2 == 0:
    print(s[mid-1], "and", s[mid])
else:
    print(s[mid])