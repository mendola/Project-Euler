#include <iostream>
#include <math.h>
#include <vector>
#define POWER 5
#define MAX 10000000
using namespace std;

int total = 0;
int sumPows(int in)
{
	int num = in;
	int sum = 0;
	while(num >= 1)
	{
		int digit = num%10;
		sum += pow(digit,POWER);
		num -= digit;
		num /= 10;
	}
//	cout<<"in: "<< in<<"  sum: "<< sum<<endl;
	if(in == sum)
		return 1;
	else return 0;
}

std::vector<int> nums(10,0);

int main()
{
	for (int i = 2; i<= MAX; i++)
		total += (i * sumPows(i));
	cout<<total<<endl;
	return 0;
}
