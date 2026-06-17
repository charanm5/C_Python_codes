from itertools import permutations

s = "abc"
print([''.join(p) for p in permutations(s)])