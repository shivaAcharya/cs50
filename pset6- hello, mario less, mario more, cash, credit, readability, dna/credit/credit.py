import string

from cs50 import get_string

cc_number = get_string("Number: ")

#ccRegex = re.compile(r'(\d{13}(\d{15,16})?)')
#mo = ccRegex.search(cc_number)

while (not cc_number.isdigit()):
    cc_number = get_string("Number: ")

# Multiply by 2 to every other digit and add digit sum to luhnSum
luhnSum = 0
for i in range(len(cc_number) - 2, -1, -2):
    productByTwo = int(cc_number[i]) * 2
    if productByTwo > 9:
        productStr = str(productByTwo)
        luhnSum = luhnSum + int(productStr[0]) + int(productStr[1])
    else:
        luhnSum += productByTwo

# Add remaining digits to luhnSum
for i in range(len(cc_number) - 1, -1, -2):
    luhnSum += int(cc_number[i])

# Check if AMEX, VISA, MASTERCARD or INVALID
if (len(cc_number) == 13 or len(cc_number) == 15 or len(cc_number) == 16) and luhnSum % 10 == 0:
    if len(cc_number) == 15 and (cc_number[:2] == '34' or cc_number[:2] == '37'):
        print("AMEX")
    elif len(cc_number) == 13 or len(cc_number) == 16 and cc_number[0] == '4':
        print("VISA")
    elif len(cc_number) == 16 and (int(cc_number[:2]) > 50 and int(cc_number[:2]) < 56):
        print("MASTERCARD")

else:
    print("INVALID")