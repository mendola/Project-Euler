import numpy as np

def FindSmallestMultiple(range,start):
	divisors = np.arange(range - 1,1,-1)
	print divisors
	run = 1
	target = start
	while run ==1:
		target = target + range
		wrong = 0
		for i in divisors:
			if target % i != 0:
				wrong = 1
				break
		if wrong == 0:
			return target
print FindSmallestMultiple(20,2520)

