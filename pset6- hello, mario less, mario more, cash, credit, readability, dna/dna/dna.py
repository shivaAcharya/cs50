import sys
import csv

# Validate proper usage
if len(sys.argv) != 3:
    sys.exit("Usage: python dna.py data.csv sequence.csv")

# Open and read sequence text file
with open(sys.argv[2], "r") as sequenceFile:
    content = sequenceFile.read()

# Dictionary -> key: STR, value: maximum consecutive repeated times
strCount = {}


# Function to calculate maximum STR repeats and update strCount
def strRepeat(content, STR):
    # Takes dna sequence content and STR and provides maximum STR repeated times.
    count, maxCount = 0, 0
    for i in range(len(content) - len(STR)):
        count = 0
        while(content[i:len(STR) + i] == STR):
            count += 1
            if count > maxCount:
                maxCount = count
            i += len(STR)
    strCount[STR] = maxCount


# List of dictionaries obtained from DictReader of database file
dataList = []

# Open database file and populate dataList
with open(sys.argv[1], "r") as dataFile:
    reader = csv.DictReader(dataFile)
    for row in reader:
        dataList.append(row)

# Calculate STR repeat for each STR
for k in dataList[0]:
    if k == 'name':
        continue
    else:
        strRepeat(content, k)

# Dictionary -> key: name, value: maximum number of match found
maxMatch = {}
for row in dataList:
    for k in strCount:
        if int(row[k]) == strCount[k]:
            if row["name"] in maxMatch:
                maxMatch[row["name"]] += 1
            else:
                maxMatch[row["name"]] = 1

# Check who has highest match and print result
iterCount = 0
for k in maxMatch:
    iterCount += 1
    if maxMatch[k] == len(strCount):
        print(k)
        break
    if iterCount == len(maxMatch) or not maxMatch:
        print("No match")