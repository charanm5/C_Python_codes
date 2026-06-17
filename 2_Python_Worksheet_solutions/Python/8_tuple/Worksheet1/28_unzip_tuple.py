lst = [(1, 'a'), (2, 'b'), (3, 'c')]
a, b = zip(*lst)
print(list(a))
print(list(b))