from PIL import Image

##load in the image
template = Image.open('LightTemplate.png')
pix = template.load()
print (template.size)

##declare the arrays for different rows of lights
row1 = []
row2 = []
row3 = []
row4 = []
row5 = []
row6 = []
row7 = []
row8 = []

##append the color value per pixel per array
for i in range(134):
    row1.append(pix[i,0])
for i in range(127):
    row2.append(pix[i,1])
for i in range(134):
    row3.append(pix[i,2])
for i in range(127):
    row4.append(pix[i,3])
for i in range(134):
    row5.append(pix[i,4])
for i in range(127):
    row6.append(pix[i,5])
for i in range(134):
    row7.append(pix[i,6])
for i in range(127):
    row8.append(pix[i,7])

##because the odd numbered light strips run right to left
##they need to be reversed in order
row1.reverse()
row3.reverse()
row5.reverse()
row7.reverse()

##make a new array that has all lights' colors
##and add each row to it
allLights = []
for i in range(len(row1)):
    allLights.append(row1[i])
for i in range(len(row2)):
    allLights.append(row2[i])
for i in range(len(row3)):
    allLights.append(row3[i])
for i in range(len(row4)):
    allLights.append(row4[i])
for i in range(len(row5)):
    allLights.append(row5[i])
for i in range(len(row6)):
    allLights.append(row6[i])
for i in range(len(row7)):
    allLights.append(row7[i])
for i in range(len(row8)):
    allLights.append(row8[i])
    
##open the output file as writable to close it as blank
open('outputFile.txt', 'w').close()

##open the now blank output file and populate it with light colors
outputFile = open('outputFile.txt', 'a')
outputFile.write(str(allLights))
outputFile.close()


