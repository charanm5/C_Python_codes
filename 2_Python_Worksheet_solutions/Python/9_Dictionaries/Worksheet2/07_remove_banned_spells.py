spells={'fireball':5,'healing':10,'curse':2}
banned=['curse','fireball']
for s in banned: spells.pop(s,None)
print(spells)
