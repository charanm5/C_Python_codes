from collections import Counter

s = "statistics"
freq = Counter(s)
min_char = min(freq, key=freq.get)
print("Least frequent character:", min_char)