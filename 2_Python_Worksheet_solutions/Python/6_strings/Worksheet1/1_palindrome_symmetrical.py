s = "madam"

palindrome = s == s[::-1]
mid = len(s) // 2
symmetric = s[:mid] == s[mid:]

print("Palindrome:", "Yes" if palindrome else "No")
print("Symmetrical:", "Yes" if symmetric else "No")