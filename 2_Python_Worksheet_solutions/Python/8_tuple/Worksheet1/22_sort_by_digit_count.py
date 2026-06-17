lst = [(1, 2), (10, 11), (3, 44)]
print(sorted(lst, key=lambda x: sum(len(str(i)) for i in x)))