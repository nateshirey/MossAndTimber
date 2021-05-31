from PIL import Image

template = Image.open('FireWorksPattern.png')
rgbImage = template.convert('RGB')
pix = template.load()
print (template.size)

w, h = template.size
numPixels = w * h

masterString = 'uint8_t neighbors [][] = {'

def Neighbors (pixel, neighborLength):
    neighborsString = ' {'
    index = 0
    for i in range(1, neighborLength):
        if pixel + i < w + 1:
            neighborsString = neighborsString + str(pixel + i) + ','
        if pixel - i > -1:
            neighborsString = neighborsString + str(pixel - i) + ','

##    for i in range(neighborLength - 2):
##        if i < 1044 - :
##            neighborsString = neighborsString + str(pixel + 134 + i - neighborLength/2)
    l = len(neighborsString)
    neighborsString = neighborsString[:l-1]
    neighborsString = neighborsString + '},'
    return neighborsString


nate = 'nate'
l = len(nate)
nate = nate[:l-1]
print(nate)
print(Neighbors(3, 5))
index = 0
for i in range(numPixels):
    xCoord = (i + w) % w
    yCoord = int((i - xCoord) / w)
    masterString = masterString + Neighbors(i, 8)
    index = index + 1
    
l = len(masterString)
masterString = masterString[:l-1]
masterString = masterString + '};'
print(masterString)
print(index)
