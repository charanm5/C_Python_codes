lst = [(1, 2), (-3, 4), (5, 6)]
print([t for t in lst if all(x > 0 for x in t)])