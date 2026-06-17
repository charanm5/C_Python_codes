
temp = float(input("Enter Temperature: "))

print("Overheat" if(temp>75) else "Normal" if(temp>=25 and temp<=75) else "Low Temp")