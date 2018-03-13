from p3 import isitprime
def primeConcatenation(a,b):
	if isitprime( int( str(a) + str(b) )) == 1:
		if isitprime( int( str(b) + str(a) )) == 1:
			return 1
		return 0
	return 0

def printPrimes(mtx):
	print "Primes:"
	for i in range(0,len(mtx)):
		print mtx[i]

primes = [0,0,0,0]
for i in range(0,len(primes)):
	primes[i] = [0,0]

primes[0][0] = 3

length = len(primes)
height = 2
primecount = 1
i = 3
while primecount <= 30:
	i += 2
        print "_______________________"
	print "current suspect: %i\n" %i
#	printPrimes(primes)
	print "end of primes \n"
	if primecount == length:
		print "Expanding width. Height = %i. Width = %i" %(height,length)
		for x in range(len(primes) ,2*len(primes)):
			primes.append([0])
			for y in range(0,height):
				primes[x].append(0)
                length = len(primes)
	if isitprime(i) == 1:
		primes[primecount][0] = i
		primecount += 1

		for k in range(0,primecount -1):
			print i
			print primes[k][0]
			if primeConcatenation(i,primes[k][0]) == 1:
				if len(primes[0]) == height:
					for x in range(0,length):
						for y in range(height,2*height):
							primes[x].append(0)
					height = len(primes[0])
				primes[k][ primes[k][1] + 2] = i
				primes[k][1] = primes[k][1] + 1

	print "Finishing for %i:\n " %i
#	printPrimes(primes)
	print "____________________________"
print "primecount = %s" % primecount

#for i in range(0, primecount - 1):
#	print primes[i]
