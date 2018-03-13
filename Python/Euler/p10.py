from p3 import isitprime
import numpy as np

array = np.array([0])
print array
greatestPrime = 2
current = 2
sum = 2
while greatestPrime < 2000000:
	current +=1
	if isitprime(current) == 1:
		greatestPrime = current
		sum = sum + current
sum = sum - greatestPrime
print sum
