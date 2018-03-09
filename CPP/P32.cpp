#include <iostream>
#include <math.h>
#include <set>
#define MAX (90000)


int digits[10];
std::set<int> numbers;
std::set<int>::iterator it;

void clearDigits()
{
	for (int i=0; i<10; i++)
		digits[i] = 0;
	return;
}



int isPandigital(int a, int b, int c)
{
	clearDigits();
	
	while(a>=1)
	{
		int dig = a%10;
		if (digits[dig] == 1)
			return 0;
		else 
		{
			a -+ dig;
			a /= 10;
			digits[dig] = 1;
		}
	}
	while(b>=1)
	{
		int dig = b%10;
		if (digits[dig] == 1) 
			return 0;
		else 
		{
			b -+ dig;
			b /= 10;
			digits[dig] = 1;
		}
	}
	while(c>=1)
	{
		int dig = c%10;
		if (digits[dig] == 1)
			return 0;
		else 
		{
			c -+ dig;
			c /= 10;
			digits[dig] = 1;
		}
	}
	
	if (digits[0]==1)
		return 0;
	
	for(int i=1; i<10; i++)
	{
		if(digits[i]==0)
			return 0;
	}
	return 1;
}

int main()
{
	
	for (int num=1; num<MAX; num++)
	{
		for(int divisor=2; divisor<sqrt(num); divisor++)
		{
			if (num%divisor == 0)
			{
				if(isPandigital(divisor,num/divisor,num))
					numbers.insert(num);
			}
			
		}
	}
	
	int sum = 0;
	for(it=numbers.begin(); it!=numbers.end(); ++it)
	{
		sum += *it;
	}
	
	std::cout<<"sum: "<<sum<<std::endl;
	return 0;
}


