s = "abcdefgh"
n = 3

print([s[i:i+n] for i in range(0, len(s), n)])