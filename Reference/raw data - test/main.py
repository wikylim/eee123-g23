
import cv2 as cv
import numpy as np
import time
from matplotlib import pyplot as plt
import pandas

#--------------- a b s o l u t e   c o o r d i n a t e s ---------

roomcoord = [100, 200, 300, 400, 500, 600]
delivery = [100, 200, 300, 400, 500, 600]
#retrieve = [245, 290]
thresholdpoint = 30

rooms = ['R1', 'R2', 'R3', 'R4', 'R5', 'NS']
colhead = ['D', '', '', '', 'R', '']

#-----------------------------------------------------------------

null = []

datared = [[0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0]]

datablu = [[0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0]]

datagur = [[0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0]]

datahaz = [[0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0]]

matrix =  [[0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0],
           [0, 0, 0, 0, 0, 0]]

redcoord = [(0, 0)]
absred=[]
tempredcoord = [(0, 0)]
tempabsred=[]

blucoord = [(0, 0)]
absblu = []
tempblucoord = [(0, 0)]
tempabsblu = []

gurcoord = [(0, 0)]
absgur = []
tempgurcoord = [(0, 0)]
tempabsgur = []

hazcoord = [(0, 0)]
abshaz = []
temphazcoord = [(0, 0)]
tempabshaz = []

targettable = '7.png'

#-----------------------------------------------------------------


def sort(datain, dataout, item, out):
    for i in range(0, len(datain)):
        for j in range(0, len(datain)-i-1):
            if (datain[j][item] > datain[j + 1][item]):
                temp = datain[j]
                datain[j]= datain[j + 1]
                datain[j + 1]= temp
    
    datain = list(datain)
    if out == 1:
        for i in range(0, len(datain)):
            if ((datain[i][item]-datain[i-1][item])>10):
                dataout.append(datain[i])

def convert(datain, matrixdata, datatype):
    lenx = len(datain)
    temp1 = datain
    temp1.insert(0, (0, 0))
    temp2 = []
    sort(temp1, temp2, 1, 1)
    leny = len(temp2)
    datain.pop(0)
    #print("")
    #print("rows: ", leny)
    #print("cols: ", lenx)
    #print("")
    for i in range(0, len(temp2)):
        for j in range(0, len(delivery)):
            if(((temp2[i][1]+thresholdpoint) > delivery[j]) and ((temp2[i][1]-thresholdpoint) < delivery[j])):
                #print("hit! row ", j)
                for k in range(0, len(datain)):
                    if(((datain[k][1]+thresholdpoint) > delivery[j]) and ((datain[k][1]-thresholdpoint) < delivery[j])):
                        #print("hit! index ", k)
                        difference_array = np.absolute(roomcoord-datain[k][0])
                        index = difference_array.argmin()
                        #print("hit! room index ", index)
                        if(matrixdata[j][index] != datatype):
                            matrixdata[j][index] = datatype;

                        
#print("[INFO] loading images...")
#image = cv.imread(targettable)
#template = cv.imread("1.png")
#cv.imshow(targettable, image)
#cv.imshow("1.png", template)

#---------------------- V i s i o n   M a n a g e m e n t ----------------------------------

img_rgb = cv.imread(targettable)
img_gray = cv.cvtColor(img_rgb, cv.COLOR_BGR2GRAY)

template = cv.imread('A.png',0)
w, h = template.shape[::-1]

res = cv.matchTemplate(img_gray,template,cv.TM_CCOEFF_NORMED)
threshold = 0.7
loc = np.where( res >= threshold)
for pt in zip(*loc[::-1]):
    cv.rectangle(img_rgb, pt, (pt[0] + w, pt[1] + h), (0,0,255), 2)
    redcoord.append(pt)
cv.imwrite('res1.png',img_rgb)
#----------------------------------------------------------------------
img_rgb = cv.imread(targettable)
img_gray = cv.cvtColor(img_rgb, cv.COLOR_BGR2GRAY)

template = cv.imread('B.png',0)
w, h = template.shape[::-1]

res = cv.matchTemplate(img_gray,template,cv.TM_CCOEFF_NORMED)
threshold = 0.8
loc = np.where( res >= threshold)
for pt in zip(*loc[::-1]):
    cv.rectangle(img_rgb, pt, (pt[0] + w, pt[1] + h), (0,0,255), 2)
    blucoord.append(pt)
cv.imwrite('res2.png',img_rgb)
#----------------------------------------------------------------------
img_rgb = cv.imread(targettable)
img_gray = cv.cvtColor(img_rgb, cv.COLOR_BGR2GRAY)

template = cv.imread('C.png',0)
w, h = template.shape[::-1]

res = cv.matchTemplate(img_gray,template,cv.TM_CCOEFF_NORMED)
threshold = 0.7
loc = np.where( res >= threshold)
for pt in zip(*loc[::-1]):
    cv.rectangle(img_rgb, pt, (pt[0] + w, pt[1] + h), (0,0,255), 2)
    gurcoord.append(pt)
cv.imwrite('res3.png',img_rgb)
#----------------------------------------------------------------------

tempredcoord = redcoord
tempblucoord = blucoord
tempgurcoord = gurcoord

print("raw1>> ")
print(redcoord)
print("raw2>> ")
print(blucoord)
print("raw3>> ")
print(gurcoord)

print("")

#---------------------- S O R T   &   C O N V E R T ----------------------------------------

sort(blucoord, absblu, 0, 1)
sort(redcoord, absred, 0, 1)
sort(gurcoord, absgur, 0, 1)


convert(absred, datared, 1)
convert(absblu, datablu, 1)
convert(absgur, datagur, 1)


convert(absred, matrix, 1)
convert(absblu, matrix, 2)
convert(absgur, matrix, 3)


#----------- b y   c o l u m n ------------------

sort(tempblucoord, tempabsblu, 1, 1)
sort(tempredcoord, tempabsred, 1, 1)
sort(tempgurcoord, tempabsgur, 1, 1)

convert(tempabsred, datared, 1)
convert(tempabsblu, datablu, 1)
convert(tempabsgur, datagur, 1)

convert(tempabsred, matrix, 1)
convert(tempabsblu, matrix, 2)
convert(tempabsgur, matrix, 3)


#-------------------------------------




#-------------------------------------------------------------------------------------

print("----- m a t r i x   r e d -----")
print(datared)
print("-----------------------------")
print("")
print("----- m a t r i x   b l u -----")
print(datablu)
print("-------------------------------")
print("")
print("----- m a t r i x   d a t -----")
print(matrix)
print("-------------------------------")
print("")
print("")
print("---- W O R K   O R D E R ------")
print("")
print(pandas.DataFrame(matrix, colhead, rooms))

            































































































