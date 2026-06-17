d={'m':1,'n':2,'o':1}
res={}
for k,v in d.items(): res.setdefault(v,[]).append(k)
print(res)
