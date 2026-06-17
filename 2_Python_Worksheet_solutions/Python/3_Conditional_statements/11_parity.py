value = int(input("Enter a 16-bit value (hex): "), 16)

ones = bin(value).count('1')

print("Parity: Even" if ones % 2 == 0 else "Parity: Odd")