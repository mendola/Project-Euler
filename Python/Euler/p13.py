import numpy as np

iFile = open('textp13.txt')

data = iFile.read()
data = data.replace('\n','')
data = data.replace(' ','')
rawdata = np.array(list(data))
rawdata = rawdata.astype(np.int)
rawdata = np.reshape(rawdata,(100,50))

carry = np.zeros(60)
sum = np.zeros(60)

msb = len(rawdata[0])
digit = 0

while digit <= msb:
	print "Working on digit %i" %digit
	count = 0
	for i in range(0,100):
		if digit < 50:
			count += int(rawdata[i][digit])
	count += int(carry[digit])
	carrydigits = 0
	count2 = count
	while count2 % 10 > 0:
		count2 /= 10
		carrydigits += 1
	sum[digit] = int(count % 10)
	print count
	count = int(count/10)
	if digit + carrydigits > msb:
		msb = digit + carrydigits
	for k in range(1,carrydigits):
		carry[digit + k] += int(count % 10)
		count = int(count / 10)

	print sum[digit]
	print carry[digit]
	digit += 1

print sum
print carry
