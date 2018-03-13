import numpy as np
import math

def countFactors(number):
	count = 2
	for k in range(2,int(math.sqrt(number)+1)):
		if number % k == 0:
			if number/k == k:
				count += 1
				print k,k
			else:
				count += 2
				print k,number/k
	return count
n = 1
sum = 1
factors = 1
while factors <= 500:
	n += 1
	sum += n
	factors = countFactors(sum)

print sum
