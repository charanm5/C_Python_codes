lst=['a','b','c','d']
res={}
cur=res
for x in lst:
    cur[x]={}
    cur=cur[x]
print(res)
