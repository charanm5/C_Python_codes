def reverse_from(lst, pos):
    return lst[:pos] + lst[pos:][::-1]

print(reverse_from([1,2,3,4,5,6], 3))