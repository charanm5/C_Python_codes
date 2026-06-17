s='abc'
subs={}
for i in range(len(s)):
    for j in range(i+1,len(s)+1):
        subs[s[i:j]]=1
print(len(subs))
