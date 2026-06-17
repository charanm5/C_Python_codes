a = 32
b = 23
c = 5

second_largest = a * ((a>b and a<c) or (a<b and a>c)) + \
                 b * ((b>a and b<c) or (b<a and b>c)) + \
                 c * ((c>a and c<b) or (c<a and c>b))
print(second_largest) 