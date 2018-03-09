#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

int MAX = 28123;
int MAX2 = 56246;
int abundantCount = 0;
int abundantNums[6966] = {0};
int comboArray[56246] = {0};
//int abundantSums[56246] = {0};

int isAbundant(int num)
{
//	cout<< "Number: "<<num<<endl;
	int maxDivisor = floor(sqrt(num));
	int smallDivisors[maxDivisor];
	int bigDivisors[maxDivisor/2+3];
	int count = 0;
	int divisors = 0;
	int sum = 0;
//	cout<< "MARKER2"<<endl;
	
	// get array of diviosrs
	for(int i=1; i <= maxDivisor; i++)
	{
		if(num % i == 0)
		{
		//	cout<< num <<"is divisible by "<< i<<"   count = "<< count<<endl;
		//	cout<< i << ".";
			smallDivisors[count] = i;
			bigDivisors[count]= num/i;
			count++;
		}
	}
	//cout<<"smallDivisors: [";
	for(int i = 0; i< count; i++)
	{
	//	cout<<smallDivisors[i]<<" ";
	}
	//cout<<"]\nbigDivisors: [";
	for(int i=0; i<count; i++)
	{
	////	cout<<bigDivisors[i]<<" ";
	}
	//cout<<"]\n";
//	cout<< "MARKER3"<<endl;
	//cout<<"count: "<<count<<endl;
	if(smallDivisors[count - 1] != sqrt(num) )
	{
//		cout<<"A"<<endl;
		for(int i=0; i<count-1; i++)
		{
	//		cout<<i<<"-";
			smallDivisors[count+i] = bigDivisors[count - 1 -i];
	//		cout<<smallDivisors[count+i]<<" ";
		}
		divisors = count*2 - 1;
	}
	else
	{
	//	cout<<"B"<<endl;
		for(int i=0; i<count-2; i++)
		{
	//		cout<<i<<" ";
			smallDivisors[count+i] = bigDivisors[count - 2 -i];
		}
		divisors = count*2 -2;
	}
	
//	cout<<"MARKER4"<<endl;
//	cout<< "DIVISORS for "<<num<<": [";
	for(int i=0; i<divisors; i++)
	{
		//cout<< smallDivisors[i]<<" ";
		sum += smallDivisors[i];
	}
	
//	cout<<"]\nThere are "<<divisors<< " divisors"<<endl;
//	cout<<"max: "<< maxDivisor<<endl;

	//cout<<"MARKER5"<<endl;
	if(sum > num)
		{
			abundantCount++;
			return 1;
		}
	else return 0;
///	cout<<"\nThere are "<<divisors<< " divisors"<<endl;
//	cout<<"max: "<< maxDivisor<<endl;

}

void findAbundantNums()
{
	for (int i = 1; i<MAX; i++)
	{
		if(isAbundant(i)==1)
		{
			abundantNums[abundantCount-1] = i;
		}
	//	cout<<i<<" ";
	}
}

void fillComboArray()
{
	for(int i =0; i<abundantCount-1; i++)
	{
		for(int j=i; j<abundantCount; j++)
		{
			comboArray[abundantNums[i] + abundantNums[j]] = 1;
		}
	}
}

int getSum()
{
	int sum = 0;
	for(int i=1; i<MAX+1; i++)
	{
	//	cout<<comboArray[i] << " ";
		if(comboArray[i] == 0)
			sum += i;	
	}
	return sum;
}
int main()
{
	clock_t t1, t2;
	t1=clock();
	//isAbundant(120);
	findAbundantNums();
	cout<<"abundantcount: "<<abundantCount<<endl;
	fillComboArray();
	cout<<" \n\nAnswer: " <<getSum()<<endl;
	t2 = clock();
	cout<< "Time to compute: "<< t2-t1<<endl;
	cout<<"done"<<endl;
}
