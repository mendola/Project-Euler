#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
	
	int rows = 0;
	string line;
	
	//Open File
	ifstream iFile("C:\\Users\\alexm\\Documents\\Text18.txt",ifstream::in);
	
	// Count rows
	if(iFile.is_open()){
		while(!iFile.eof()){
			getline(iFile,line);
			cout << line << endl;
			rows++;
		}
	}
	
	cout<<"\n"<<rows<<" rows"<<endl;
	
	// initialize matrix
	int pyramid[rows][rows] = {{0}};
	int cols = 1;
	
	// return to beginning of file
	iFile.clear();
	iFile.seekg(0, ios::beg);
	
	// Read in pyramid
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			iFile >> pyramid[j][i];
			cout<<pyramid[j][i]<<" ";
		}
		cout<<"\n";
		cols++;
	}
	
	
	for(int i=rows-2; i>=0; i--)
	{
		for(int j=0; j<=i; j++)
		{
			pyramid[j][i] = pyramid[j][i] + max(pyramid[j][i+1], pyramid[j+1][i+1]);
		}
	}
	
	cout<<"\n\nResult: "<<pyramid[0][0]<<endl;

cols=1;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			iFile >> pyramid[j][i];
			cout<<pyramid[j][i]<<" ";
		}
		cout<<"\n";
		cols++;
	}
	
	iFile.close();
	return 0;
}
