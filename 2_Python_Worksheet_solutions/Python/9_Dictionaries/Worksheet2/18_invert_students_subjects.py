d={'math':{'john':90,'jane':80},'science':{'john':85,'jane':95}}
res={}
for sub,students in d.items():
    for s,m in students.items():
        res.setdefault(s,{})[sub]=m
print(res)
