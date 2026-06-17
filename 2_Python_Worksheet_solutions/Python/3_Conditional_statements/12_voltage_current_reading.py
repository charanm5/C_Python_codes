voltage = float(input("Enter voltage (V): "))
current = float(input("Enter current (mA): "))

print(
    "Power OK" if (3.0 <= voltage <= 3.3 and 10 <= current <= 500) else
    "Power Error" if (not (3.0 <= voltage <= 3.3) and not (10 <= current <= 500)) else
    "Voltage Error" if not (3.0 <= voltage <= 3.3) else
    "Current Error"
)