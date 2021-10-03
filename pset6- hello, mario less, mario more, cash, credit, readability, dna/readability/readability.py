from cs50 import get_string
import string
import math

# Get user's input
text = get_string("Text: ")

letters, words, sentences = 0, 1, 0

# Check for letters, words, and sentences
for char in text:
    if char.isalpha():
        letters += 1
    if char == ' ':
        words += 1
    if char == '.' or char == '!' or char == '?':
        sentences += 1

# Calculate Coleman-Liau index
index = round(0.0588 * (letters / words) * 100 - 0.296 * (sentences / words) * 100 - 15.8)

# Print readability grade level
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade ", index)

