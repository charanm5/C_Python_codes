def reverse_string(s):
    if len(s) <= 1:      # base case
        return s

    return reverse_string(s[1:]) + s[0]

reverse_string("hello")