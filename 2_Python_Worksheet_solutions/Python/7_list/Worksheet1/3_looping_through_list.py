nums = [1, 2, 3, 4, 5]

for n in nums:
    print(n)

i = 0
while i < len(nums):
    print(nums[i])
    i += 1

squares = [n*n for n in nums]
print(squares)