from PIL import Image

##load in the image
template = Image.open('LightTemplate.png')
pix = template.load()
print (template.size)

##declare the arrays for different rows of lights
##because this read top left to bottom right,
##row8 is the bottom row and row1 is the top
row1 = []
row2 = []
row3 = []
row4 = []
row5 = []
row6 = []
row7 = []
row8 = []

##append the color value per pixel per array
for i in range(127):
    row1.append(pix[i + 3,7])
for i in range(134):
    row2.append(pix[i,6])
for i in range(127):
    row3.append(pix[i + 3,5])
for i in range(134):
    row4.append(pix[i,4])
for i in range(127):
    row5.append(pix[i + 3,3])
for i in range(134):
    row6.append(pix[i,2])
for i in range(127):
    row7.append(pix[i + 3,1])
for i in range(134):
    row8.append(pix[i,0])

##because the odd numbered light strips run right to left
##they need to be reversed in order
row1.reverse()
row3.reverse()
row5.reverse()
row7.reverse()

##make a new array that has all lights' colors
##and add each row to it
allReds = []
allGreens = []
allBlues = []

for i in range(len(row1)):
    allReds.append(row1[i][0])
    allGreens.append(row1[i][1])
    allBlues.append(row1[i][2])
for i in range(len(row2)):
    allReds.append(row2[i][0])
    allGreens.append(row2[i][1])
    allBlues.append(row2[i][2])
for i in range(len(row3)):
    allReds.append(row3[i][0])
    allGreens.append(row3[i][1])
    allBlues.append(row3[i][2])
for i in range(len(row4)):
    allReds.append(row4[i][0])
    allGreens.append(row4[i][1])
    allBlues.append(row4[i][2])
for i in range(len(row5)):
    allReds.append(row5[i][0])
    allGreens.append(row5[i][1])
    allBlues.append(row5[i][2])
for i in range(len(row6)):
    allReds.append(row6[i][0])
    allGreens.append(row6[i][1])
    allBlues.append(row6[i][2])
for i in range(len(row7)):
    allReds.append(row7[i][0])
    allGreens.append(row7[i][1])
    allBlues.append(row7[i][2])
for i in range(len(row8)):
    allReds.append(row8[i][0])
    allGreens.append(row8[i][1])
    allBlues.append(row8[i][2])


##convert color arrays to strings
allRedsString = 'uint8_t flowReds [] = {'
for i in range(len(allReds) - 1):
    allRedsString = allRedsString + str(allReds[i]) + ','

allRedsString = allRedsString + str(allReds[len(allReds) - 1]) + '};\n'

allGreensString = 'uint8_t flowGreens [] = {'
for i in range(len(allGreens) - 1):
    allGreensString = allGreensString + str(allGreens[i]) + ','

allGreensString = allGreensString + str(allGreens[len(allGreens) - 1]) + '};\n'

allBluesString = 'uint8_t flowBlues [] = {'
for i in range(len(allBlues) - 1):
    allBluesString = allBluesString + str(allBlues[i]) + ','

allBluesString = allBluesString + str(allBlues[len(allBlues) - 1]) + '};\n'


##file writing
##open and close the temp file to clear it
open('tempFile.txt', 'w').close()

##open the arduino file and the temp file
file = open('Drip.ino')
temp = open('tempFile.txt', 'w')


lineNumber = 0
##flags to mark the start and end of the color array zone
foundStartFlag = False
foundEndFlag = False

##write the arduino file lines to temp until the start flag is hit
for line in file:
    if foundStartFlag:
        break
    if '//paste colors here' in line:
        foundStartFlag = True
    temp.write(line)

##write the color arrays and a blank line
temp.write(allRedsString)
temp.write(allGreensString)
temp.write(allBluesString)
temp.write('\n')

##write the end flag
temp.write('//end paste block\n')

##read the arduino file and write the lines after the end flag to temp
for line in file:
    if foundEndFlag == True:
        temp.write(line)
    if '//end paste block' in line:
        foundEndFlag = True

##close both files
temp.close()
file.close()

##reopen both files with the correct access mode
file = open('Drip.ino', 'w')
temp = open('tempFile.txt')

##overwrite the arduino file using the temp file
for line in temp:
    file.write(line)

file.close()
temp.close()




