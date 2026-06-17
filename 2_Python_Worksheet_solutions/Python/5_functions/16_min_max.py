def min_max(numbers):
    smallest = min(numbers)
    largest = max(numbers)
    return smallest, largest

nums = [4, 7, 1, 9, 3]

minimum, maximum = min_max(nums)

print("Smallest:", minimum)
print("Largest:", maximum)