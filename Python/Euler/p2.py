import numpy as np

subsum = 2
a = 1
b = 1
sum = 2
while subsum <= 40:
	a = subsum + b
	b = subsum + a
	subsum = a + b
	sum = sum + subsum
	print sum,subsum,a,b

print sum-subsum
