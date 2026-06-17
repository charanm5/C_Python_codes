msg='hello world'
vowels=set('aeiou')
print(sum(1 for ch in msg.lower() if ch in vowels))
