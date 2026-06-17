freq = int(input("Enter signal frequency (Hz): "))

print(
    "Low Band" if freq < 1000 else
    "Mid Band" if freq <= 9999 else
    "High Band" if freq <= 99999 else
    "Out of Range"
)