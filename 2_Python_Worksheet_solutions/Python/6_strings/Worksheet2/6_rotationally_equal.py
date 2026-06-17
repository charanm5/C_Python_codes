s1 = "abcde"
s2 = "cdeab"

print("Rotationally equivalent:", "Yes" if s2 in (s1 + s1) else "No")