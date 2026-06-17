s = "education"
vowels = set("aeiou")
count = sum(1 for ch in s if ch in vowels)
print("Vowels Count:", count)