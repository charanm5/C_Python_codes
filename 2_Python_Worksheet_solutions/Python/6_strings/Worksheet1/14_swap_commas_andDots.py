s = "23,45.89,78.90"
s = s.replace(",", "#").replace(".", ",").replace("#", ".")
print(s)