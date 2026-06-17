words=['education','python','sequoia']
v=set('aeiou')
print([w for w in words if v.issubset(set(w))])
