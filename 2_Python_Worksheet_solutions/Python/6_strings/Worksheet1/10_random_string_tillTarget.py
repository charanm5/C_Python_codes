import random
import string

target = "abc"
count = 0

while True:
    rand = ''.join(random.choice(string.ascii_lowercase) for _ in range(len(target)))
    count += 1
    if rand == target:
        print(f"Generated '{rand}' after {count} attempts")
        break