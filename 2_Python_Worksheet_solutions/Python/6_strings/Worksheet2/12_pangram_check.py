import string

s = "The quick brown fox jumps over the lazy dog"
print("Is pangram:", set(string.ascii_lowercase) <= set(s.lower()))