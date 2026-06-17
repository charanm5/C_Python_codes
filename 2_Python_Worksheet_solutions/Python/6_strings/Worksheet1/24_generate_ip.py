def valid_ip(s):
    res = []
    for i in range(1,4):
        for j in range(i+1,i+4):
            for k in range(j+1,j+4):
                a,b,c,d = s[:i], s[i:j], s[j:k], s[k:]
                if all([a,b,c,d]) and all(0<=int(x)<=255 and str(int(x))==x for x in [a,b,c,d]):
                    res.append(".".join([a,b,c,d]))
    return res

print(valid_ip("25525511135"))