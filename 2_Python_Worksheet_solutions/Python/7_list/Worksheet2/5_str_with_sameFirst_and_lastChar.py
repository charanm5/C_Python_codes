lst = ['abc', 'xyz', 'aba', '1221']
count = sum(1 for s in lst if len(s) >= 2 and s[0] == s[-1])
print(count)