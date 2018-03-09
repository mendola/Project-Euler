#include <iostream>
#include <math.h>

using namespace std;

void generatePrimes(int *notPrimeMap, int length)
{
	notPrimeMap[0] = 1;
	notPrimeMap[1] = 1;
	notPrimeMap[2] = 0;
	notPrimeMap[3] = 0;
	
	int maxseed = floor(sqrt(length));
	for (int i=2; i<maxseed;i++)
	{
		for (int j=i; j<maxseed; j++)
		{
			notPrimeMap[i*j] = 1;
		}
	}
}

int countPrimeSequence(int * primes, int a, int b)
{
	int count = 0;
	int running = 0;
	do
	{
		int f = (count*count) + (a*count) + b;
		if (f<1)
			return count;
		count++;
		running= primes[f];
	} while(running==0);
	return count-1;
}

int main()
{
	int length = 2000000;
	int *primes = new int[length] ();
	generatePrimes(primes, length);
	
	int maxCount = 0;
	int aMax = 0;
	int bMax = 0;
	int theCount = 0;
	for (int i = -999; i<1000; i++)
	{
		for (int j = -999; j<1000; j++)
		{
			theCount = countPrimeSequence(primes,i,j);
			if(theCount>maxCount)
			{
				maxCount = theCount;
				aMax = i;
				bMax = j;
			}
		}
	}
		
	
	cout<< "the answer is "<< aMax*bMax<<endl;
	
	delete [] primes;
	return 0;
}
