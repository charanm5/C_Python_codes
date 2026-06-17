value = int(input("Enter value (0-255): "))

quadrant = (
    "Quadrant 1" if 0 <= value <= 63 else
    "Quadrant 2" if 64 <= value <= 127 else
    "Quadrant 3" if 128 <= value <= 191 else
    "Quadrant 4" if 192 <= value <= 255 else
    "Invalid input"
)

print(quadrant)