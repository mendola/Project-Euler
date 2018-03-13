import numpy as np

range = np.arange(1,101)

sumSquares = np.sum(range*range)

squaredSum = np.sum(range)*np.sum(range)

print squaredSum - sumSquares
