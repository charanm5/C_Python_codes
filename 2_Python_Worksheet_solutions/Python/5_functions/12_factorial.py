def factorial(n):
    if n == 0 or n == 1:  # base case
        return 1
    return n * factorial(n - 1)  # recursive case

print(factorial(5))