import numpy as np
iFile = open('textp8.txt')
rawdata = iFile.read()
rawdata = rawdata.strip('\n')
rawdata = rawdata.replace('\n','')

data = np.array(list(rawdata), dtype=int)
maxproduct = 1
for i in range(0,len(data)-12):
	product = 1
	for k in range(i,i+13):
		product = product*data[k]

	if product > maxproduct:
		maxproduct = product
print maxproduct
