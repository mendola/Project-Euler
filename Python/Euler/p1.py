import numpy as np

threes = np.arange(0,1000,3)
fives = np.arange(0,1000,5)
mask = np.arange(0,len(fives)-1,3)

fives = np.delete(fives,mask)

print "threes:",threes
print "fives:",fives

sum = np.sum(fives) + np.sum(threes)

print sum
