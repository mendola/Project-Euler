from p3 import isitprime

i = 1
count = 0
biggestprime = 0;
while count < 10001:
	i +=1
	if isitprime(i) == 1:
		biggestprime = i
		count +=1
print biggestprime

