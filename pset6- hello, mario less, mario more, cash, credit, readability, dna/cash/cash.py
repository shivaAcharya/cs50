from cs50 import get_float

# Get user input
change = get_float("Change owed: ")

# Validate user's input
while (change < 0):
    change = get_float("Change owed: ")

count = 0

# Provide 25 cent if change is than 0.25
while (change >= 0.25):
    count += 1
    change = round(change - 0.25, 2)

# Provide 10 cent if change is than 0.10
while (change >= 0.10):
    count += 1
    change = round(change - 0.10, 2)

# Provide 5 cent if change is than 0.05
while (change >= 0.05):
    count += 1
    change = round(change - 0.05, 2)

# Provide 1 cent if change is than 0.01
while (change >= 0.01):
    count += 1
    change = round(change - 0.01, 2)

print(count)
