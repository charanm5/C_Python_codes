def calculate(a: int, b: int) -> list:
    return a+b,a-b
    
s, d = calculate(3,4)
print("Sum: ",s)
print("Difference: ",d)