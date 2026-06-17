nums=[10,15]
res={}
for n in nums:
    for i in range(1,n+1):
        if n%i==0: res[i]=res.get(i,0)+1
print(res)
