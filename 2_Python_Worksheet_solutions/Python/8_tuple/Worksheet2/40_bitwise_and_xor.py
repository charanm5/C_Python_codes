t1 = (1, 2, 3)
t2 = (2, 2, 2)

and_res = tuple(a & b for a, b in zip(t1, t2))
xor_res = tuple(a ^ b for a, b in zip(t1, t2))

print("AND:", and_res)
print("XOR:", xor_res)