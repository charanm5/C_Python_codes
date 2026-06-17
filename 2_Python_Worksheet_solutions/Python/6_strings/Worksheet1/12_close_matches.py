from difflib import get_close_matches

target = "apple"
lst = ["apply", "apples", "ape", "maple"]
print(get_close_matches(target, lst))