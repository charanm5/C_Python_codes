n = 150 
k = 2

result = ((n << k) | (n >> (8 - k))) & 0xFF

print(result)