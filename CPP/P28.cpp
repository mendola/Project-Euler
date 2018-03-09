#include <iostream>
#include <math.h>
#define SIDELENGTH 1001

using namespace std;


int generateSpiral(int ** matrix, int sidelength)
{
	int i = ceil(sidelength / 2);
	int j = ceil(sidelength / 2);
	
	int side = 0;
	int num = 1;
	
	matrix[i][j] = num;
	cout<< "i= "<<i<< "  j= "<<j<<endl;
	while(side<sidelength-1)
	{
	//	cout<<"num at: "<<num;
		side++;   
		for(int r = 1; r<=side; r++)
		{
			j++;
		//	cout<<"right "<< " num: "<<num<<" i= "<<i<< "  j= "<<j<<endl;
			num++;
			matrix[i][j] = num;
		}
		for(int d = 1; d<=side; d++)
		{
			i++;
		//	cout<<"down  "<< " num: "<<num<< "i= "<<i<< "  j= "<<j<<endl;
			num++;
			matrix[i][j] = num;
		}
		side++;
		for(int l = 1; l<=side; l++)
		{
			j--;
		//	cout<<"left  "<< " num: "<<num<< "i= "<<i<< "  j= "<<j<<endl;
			num++;
			matrix[i][j] = num;
		}
		for(int u=1; u<=side; u++)
		{
			i--;
		//	cout<<"up    "<< " num: "<<num<< "i= "<<i<< "  j= "<<j<<endl;
			num++;
			matrix[i][j] = num;
		}
	}
	
	for(int r=1; r<=side; r++)
	{
		j++;
		num++;
		matrix[i][j] = num;
	}
}

int computeDiagSum(int** matrix)
{
	int sum = 0;
	for(int i = 0; i<SIDELENGTH; i++)
	{
		sum += matrix[i][i];
		sum += matrix[i][SIDELENGTH-i-1];
	}
	return sum-1;
}
int main()
{
	cout<<"initializing matrix..."<<endl;
	
	int **matrix = new int*[SIDELENGTH];
	for (int i = 0; i< SIDELENGTH;i++)
		matrix[i] = new int[SIDELENGTH] ();
		
	cout<<"matrix initialized."<<endl;
	int dim = SIDELENGTH;
	
	generateSpiral(matrix, dim);
	
	int sum = computeDiagSum(matrix);
	cout<<"the answer is: "<<sum<<endl;
	
	for (int i= 0; i<SIDELENGTH; i++)
		delete [] matrix[i];
	delete [] matrix;
		
	return 0;
	
}
