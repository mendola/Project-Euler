import numpy as np
import math

max = int(1000/(2+math.sqrt(2)))
print max
for i in range(1,max):
	for k in range(1,1000):
		if float(math.sqrt(i*i+k*k)) + i + k == 1000:
			print i,k,float(math.sqrt(i*i+k*k))
