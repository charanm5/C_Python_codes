import re

s = "MyPass123@"

valid = (len(s) >= 8 and
         re.search(r"[A-Z]", s) and
         re.search(r"[a-z]", s) and
         re.search(r"\d", s) and
         re.search(r"[@#$%^&+=]", s))

print("Valid password:", "Yes" if valid else "No")