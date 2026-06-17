t = (("11", "22"), ("33", "44"))
print(tuple(tuple(int(x) for x in sub) for sub in t))