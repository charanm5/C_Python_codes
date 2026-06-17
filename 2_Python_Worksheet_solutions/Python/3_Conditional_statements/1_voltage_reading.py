voltage = float(input("Enter voltage: "))

print("Nominal Voltage" if(voltage >= 3.0 and voltage <= 3.3) \
    else "Over Voltage" if(voltage > 3.3) else "Under Voltage")