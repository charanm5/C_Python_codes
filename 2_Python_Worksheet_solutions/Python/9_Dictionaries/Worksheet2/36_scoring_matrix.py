students=['A','B']
subjects=['math','sci']
scores=[[90,80],[85,95]]
print({students[i]:dict(zip(subjects,scores[i])) for i in range(len(students))})
