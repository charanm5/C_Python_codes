d={'x':{'p':1},'y':{'q':2}}
res={}
for o,inner in d.items():
    for k,v in inner.items():
        res[k]={o:v}
print(res)
