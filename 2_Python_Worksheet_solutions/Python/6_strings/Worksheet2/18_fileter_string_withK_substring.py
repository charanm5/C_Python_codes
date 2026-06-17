lst = ["applebanana", "apple", "banana", "applebananacherry"]
subs = ["apple", "banana"]

res = [s for s in lst if all(sub in s for sub in subs)]
print(res)