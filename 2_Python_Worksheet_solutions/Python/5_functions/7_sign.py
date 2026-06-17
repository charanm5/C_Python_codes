def sign(num: int) -> str:
    return "Positive" if (num > 0) else "Negative" if (num < 0) else "Zero"
    
result = sign(95)
print(result)