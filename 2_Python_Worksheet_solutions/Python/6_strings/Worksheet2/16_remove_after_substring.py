s = "abcdeFGhiJK"
sub = "FG"

idx = s.find(sub)
print(s[:idx + len(sub)] if idx != -1 else s)