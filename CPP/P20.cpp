#include <iostream>

using namespace std;

int sumProperDivisors(int num)
{
	int n = 1;
	int sum = 0;
	while(n < num)
	{
		if( num % n == 0)
		{
			sum += n;
		}
		n++;
	}
	return sum;
}

int isAmicable(int num)
{
	int a = sumProperDivisors(num);
	if(num == sumProperDivisors(a) && num != a) 
		return 1;
	else return 0;
}

int main()
{
	int total = 0;
	
	for(int i=220; i<=10000; i++)
	{
		if(1==isAmicable(i))
		{
			cout<< i<<" ";
			total += i;
		}
	}	
	
	cout << "\nthe answer is: " << total<<endl;
	
	cout << isAmicable(220)<<endl;
	return 0;
}




