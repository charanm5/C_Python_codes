words=['bat','tab','eat','tea','tan','nat']
res={}
for w in words: res.setdefault(''.join(sorted(w)),0); res[''.join(sorted(w))]+=1
print(max(res.values()))
