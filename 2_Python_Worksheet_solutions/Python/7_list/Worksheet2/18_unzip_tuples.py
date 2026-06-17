lst = [(1, 'a'), (2, 'b'), (3, 'c')]
x, y = zip(*lst)
print(list(x), list(y))