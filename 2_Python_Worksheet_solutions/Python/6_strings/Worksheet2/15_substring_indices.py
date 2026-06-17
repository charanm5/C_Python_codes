s = "abracadabra"
sub = "abra"

res = []
i = 0

while i <= len(s) - len(sub):
    if s[i:i+len(sub)] == sub:
        res.append(i)
    i += 1

print(res)