s = "I have one apple and two oranges."
d = {"one":"1", "two":"2"}

for k,v in d.items():
    s = s.replace(k, v)

print(s)