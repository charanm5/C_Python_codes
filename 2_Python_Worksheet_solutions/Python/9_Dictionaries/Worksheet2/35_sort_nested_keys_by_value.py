d={'group1':{'b':2,'a':1},'group2':{'c':3,'d':0}}
print({k:sorted(v.items(),key=lambda x:x[1]) for k,v in d.items()})
