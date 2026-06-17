import copy
original = {'nums': [1, 2, 3]}
shallow = original.copy()
deep = copy.deepcopy(original)
shallow['nums'].append(4)
print('Original:', original)
print('Shallow:', shallow)
print('Deep:', deep)
