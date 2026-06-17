d={'x':[5,5],'y':[1,2,3],'z':[10]}
print(sorted(d.items(),key=lambda x:sum(x[1])))
