lst = ["hellohello", "world", "testtesttest"]

def reduce_str(s):
    for i in range(1, len(s)//2 + 1):
        if s == s[:i] * (len(s)//i):
            return s[:i]
    return s

print([reduce_str(x) for x in lst])