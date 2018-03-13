#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#define HEIGHT 100
#define WIDTH 50

int offset = 1;
int width = WIDTH;
vector<int> carry;
vector<int> sum;

int main()
{
carry.resize(WIDTH);
sum.resize(WIDTH);
ifstream iFile("/home/alex/ProjectEuler/CPP/p13text.txt");
vector< vector<int> > data;
data.resize(HEIGHT);
for(int i = 0; i<HEIGHT;i++)
{
	data[i].resize(WIDTH);
}

int i = 0;
int j = 0;
char buf;
//Read into 100x50 array
for(j = 99; j>=0; j--)
{
	for(i=49; i>=0;i--)
		{
			iFile.get(buf);
			if(buf!='\n')
			{
			data[j][i] = buf - '0';
			cout<<buf;
			}
			else cout<<buf<<endl;
		}
		i=0;
}


carry[0]=0;

for(i=0;i<width;i++)
{
	offset = 1;
	cout<<"i = "<<i<<endl;
	int count = 0;
	for(j=0;j<HEIGHT;j++)
	{
		count = data[j][i] + count;
	}

	count = count + carry[i];

	sum[i] = count % 10;
	count = count / 10;
	while(count !=0)
	{
		if (carry.size() < (i+offset))
		{
			cout<<"RESIZING . i+offset= "<<i+offset<<endl;
			carry.resize(i+offset);
			sum.resize(i+offset);
			cout<< "  ...done.  carry size: "<<carry.size()<<endl;
		}
		carry[i+offset] = carry[i+offset] + count % 10;
		count = count / 10; 
		cout<<"carry: " << carry[i+offset]<<"  count: "<<count<<endl;
		offset = offset + 1;
	}
	cout <<width;
}

cout<<"FINISHING"<<endl;
for(i = WIDTH; i<carry.size(); i++)
{

}

cout<<"Exiting"<<endl;
return 0;
}

