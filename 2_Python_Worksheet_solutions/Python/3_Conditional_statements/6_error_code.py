
code = int(input("Enter Number: "))

print("Critical" if(code >= 1000) else "Warning" if (code >= 100 and code <= 999) else "Info")