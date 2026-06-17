a = 14
b = 27
c = 19

largest = a * (a >= b and a >= c) + \
          b * (b > a and b >= c) + \
          c * (c > a and c > b)

print(largest)