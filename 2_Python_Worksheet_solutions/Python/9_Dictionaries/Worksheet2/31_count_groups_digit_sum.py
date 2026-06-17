nums=[11,20,12,21,3]
res={}
for n in nums:
 s=sum(map(int,str(n))); res[s]=res.get(s,0)+1
print(max(res.values()))
