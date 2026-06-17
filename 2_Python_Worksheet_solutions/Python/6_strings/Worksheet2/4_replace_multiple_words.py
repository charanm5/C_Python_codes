s = "I like apples and bananas."
rep = {"apples": "oranges", "bananas": "grapes"}

for k, v in rep.items():
    s = s.replace(k, v)

print(s)