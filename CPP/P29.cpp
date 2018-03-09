#include <iostream>
#include <math.h>
#define MAX 100
#define MIN 2
using namespace std;
//1  2  3   4        5       6     7    8		9   10	 11   12

//2  4  8   16       32     64    128   256    512 1024 2048 4096 

//3 9  27   81      243    729    2187 6561

//4 16 64  256     1024   4096

//8 64 512 4096   32768

//9 81 729 6561   59049

//16 256  4096

//27 729 

//81 6561
int main()
{

//int total = (MAX - MIN + 1)*(MAX - MIN + 1);
int totals[MAX+1] = {0};
totals[MIN] = (MAX - MIN + 1);
int answer = 0;
for(int a=MIN; a<=MAX; a++)
{
	if(totals[a]==0)
	{
		totals[a] = (MAX - MIN + 1);	
	}
	
		int num = a*a;
		int count = 1;
		while(num<=MAX)
		{
			if(totals[num]==0)
				totals[num] = (MAX - MIN + 1);
			count++;
			totals[num] = totals[num] - floor( totals[a] / count) -1;
			num = num*a;
		}
}

for (int i = MIN; i<=MAX; i++)
{
	cout<<i<<":"<<totals[i]<<" ";
	answer = answer + totals[i];
}

cout<<"\nanswer = "<<answer<<endl;
return 0;
}
