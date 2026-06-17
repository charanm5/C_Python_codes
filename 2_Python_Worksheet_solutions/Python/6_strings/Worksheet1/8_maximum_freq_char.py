from collections import Counter

s = "banana"
freq = Counter(s)
max_char = max(freq, key=freq.get)
print("Maximum frequency character:", max_char)