list1 = ["a", "b", "c"]
list2 = [1, 2, 3]

new_list = list1 + list2

list1.extend(list2)

print(new_list)
print(list1)
print(list2)