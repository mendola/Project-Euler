#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{

ifstream iFile("/home/alex/ProjectEuler/CPP/p13text.txt");
int data[100][50];

int i = 0;
int j = 0;
char buf;
//Read into 100x50 array
for(j = 0; j<100; j++)
{
	for(i=0; i<=50;i++)
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




cout << "done"<<endl;
return 0;
}

