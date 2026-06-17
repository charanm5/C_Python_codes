s1 = "red blue green"
s2 = "blue yellow red"

set1 = set(s1.split())
set2 = set(s2.split())

print(list(set1 ^ set2))