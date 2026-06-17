l1 = int(input("LED1 (0/1): "))
l2 = int(input("LED2 (0/1): "))
l3 = int(input("LED3 (0/1): "))

on_leds = []

if l1 == 1:
    on_leds.append("LED1")
if l2 == 1:
    on_leds.append("LED2")
if l3 == 1:
    on_leds.append("LED3")

print(" ".join(on_leds) + " ON" if on_leds else "All LEDs off")