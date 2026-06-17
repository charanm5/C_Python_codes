dicts=[{'a':[5,1]},{'a':[3,4]},{'a':[7,0]}]
index=1
print(sorted(dicts,key=lambda d:d['a'][index]))
