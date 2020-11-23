from PIL import Image

template = Image.open('LightTemplate.png')
pix = template.load()
print (template.size)

arduinoFile = open('simpleNate.ino', 'w')
data = arduinoFile.read()
print(data)

row1 = []
row2 = []
row3 = []
row4 = []
row5 = []
row6 = []
row7 = []
row8 = []

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


