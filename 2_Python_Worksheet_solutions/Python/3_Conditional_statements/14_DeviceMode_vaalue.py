mode = int(input("Enter device mode (0/1/2): "))

if mode == 0:
    print("Standby")
elif mode == 1:
    print("Active")
elif mode == 2:
    print("Fault")
else:
    print("Unknown mode")