import numpy as np

def ispalindrome(num):
	a = str(num)
	b = str("")
	for i in range(0,len(a)):
		b+= a[len(a)-1-i]
	if a == b:
		return 1
	return 0

def findmaxpalindrome():
	a = np.arange(999,100,-1)
	maxpal = 1
	for i in a:
		for j in a:
			if 1==ispalindrome(i*j):
				if i*j > maxpal:
					maxpal = i*j
	return maxpal

print findmaxpalindrome()
