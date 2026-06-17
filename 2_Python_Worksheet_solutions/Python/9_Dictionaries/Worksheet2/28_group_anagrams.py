words=['listen','silent','enlist','hello','ohlle']
res={}
for w in words: res.setdefault(''.join(sorted(w)),[]).append(w)
print(list(res.values()))
