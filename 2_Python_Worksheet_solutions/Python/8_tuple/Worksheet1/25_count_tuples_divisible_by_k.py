lst = [(3, 6), (9, 12, 15), (4, 8)]
k = 3

print(sum(all(x % k == 0 for x in t) for t in lst))