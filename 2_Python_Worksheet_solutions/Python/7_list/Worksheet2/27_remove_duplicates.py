lst = [1,2,2,3,4,4,5,6,5]
res = []
for i in lst:
    if i not in res:
        res.append(i)
print(res)