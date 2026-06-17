import string

s = "Hello, world! How are you?"
print("".join(ch for ch in s if ch not in string.punctuation))