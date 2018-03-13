import math

BIG = 600851475143

def isitprime(num):
	i = 2
	while i<=math.sqrt(num):
		if num % i == 0:
			return 0
		i = i + 1
	return 1


#for k in range(2,int(math.sqrt(BIG))):
#	if  BIG % k == 0:
#		print "%r / %r = %r" %(BIG,k,BIG/k)
#		a = BIG/k
#		if isitprime(a) == 1:
#			print "The largest prime factor of %i is %i" %(BIG,BIG/k)
#		elif isitprime(k) ==1:
#			print "A prime factor (not necessarily biggest) is %d" %k

