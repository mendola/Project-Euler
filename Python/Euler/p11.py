import numpy as np

iFile = open('textp11.txt')
rawdata = iFile.read()

data = np.fromstring(rawdata,dtype=int,sep=' ')
data = data.reshape(20,20)

def lineproduct(matrix,x,y,dir):
	if dir=="right":
		return matrix[y][x]*matrix[y][x+1]*matrix[y][x+2]*matrix[y][x+3]
	elif dir=="down":
		return matrix[y][x]*matrix[y+1][x]*matrix[y-2][x]*matrix[y+3][x]
	elif dir=="diagdown":
		return matrix[y][x]*matrix[y+1][x+1]*matrix[y+2][x+2]*matrix[y+3][x+3]
	elif dir=="diagup":
                return matrix[y][x]*matrix[y-1][x+1]*matrix[y-2][x+2]*matrix[y-3][x+3]

maxproduct = 0

for i in range(0,17):
	for j in range(0,20):
		if lineproduct(data,i,j,"right") > maxproduct:
			maxproduct = lineproduct(data,i,j,"right")
for i in range(0,17):
        for j in range(0,17):
                if lineproduct(data,i,j,"diagdown") > maxproduct:
                        maxproduct = lineproduct(data,i,j,"diagdown")
for i in range(0,20):
        for j in range(0,17):
                if lineproduct(data,i,j,"down") > maxproduct:
                        maxproduct = lineproduct(data,i,j,"down")
for i in range(0,17):
        for j in range(3,20):
                if lineproduct(data,i,j,"diagup") > maxproduct:
                        maxproduct = lineproduct(data,i,j,"diagup")

print maxproduct
