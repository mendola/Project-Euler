#include <iostream>
#include <cstdlib>

using namespace std;

unsigned long int maxIndex = 1;
int maxCount = 1;

int main()
{
	for (unsigned long int j = 113381; j<=1000000;j++)
	{
		 unsigned long int i = j;
		cout <<i<<"   maxCount" << maxCount<<endl;
		 int count = 0;
		while(i!=1)
		{
			if(i % 2!=0)
			{
				i = (3*i + 1);
				//cout<<i<<" ";
				count++;
			}
			else
			{
				i = i/2;
				//cout<<i<< " ";
				count++;
			}
		}
		cout<<"\n";
		if (count>maxCount)
			{maxCount = count;
			maxIndex = j;}
	}

	cout<<"index: "<<maxIndex<<"  maxCount: "<<maxCount<<endl;
	return 0;
}