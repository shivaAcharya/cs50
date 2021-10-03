from cs50 import get_int

# Get height input from user
height = get_int("Height: ")

# Make sure the height is less than 8
while (0 >= height or height > 8):
    height = get_int("Height: ")

# Print double half-pyramid
for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i + "  " + "#" * i)