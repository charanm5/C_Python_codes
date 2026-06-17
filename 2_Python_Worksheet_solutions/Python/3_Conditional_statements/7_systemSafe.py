flags = "power_on"

power_on = 1
overcurrent = 1
overvoltage = 1

print("System Safe" if(power_on and not overcurrent and not overvoltage) else "Critical Failure" if(overcurrent and overvoltage) \
        else "Shut Down: Overcurrent" if(overcurrent) else "Shut Down: Overvoltage" if(overvoltage) else "")