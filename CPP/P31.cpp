#include <iostream>
#include <math.h>
using namespace std;
#define COINTYPES (8)

int coins[COINTYPES] = {1, 2, 5, 10, 20, 50, 100, 200};

int getLargestCoin(int num)
{
	for(int i = COINTYPES - 1; i>=0; i--)
	{
		if(num >= coins[i])
			return coins[i];
	}
}

int numCombos(int num)
{
	static int combos = 0;
	if(num==0)
		return 0;
	if(num==1)
		return 1;
		
	if (num==getLargestCoin(num))
		return 1+ numCombos(getLargestCoin(num-1)) + numCombos(num - 1 - getLargestCoin(num-1));
	else combos = numCombos(getLargestCoin(num)) + numCombos(num - getLargestCoin(num));


	cout<<combos++<<endl;
	return combos;
}



int main()
{
	int combos=0;
	for(int a=200; a>= 0; a-=200){
		for(int b=a; b>=0; b-=100){
			for(int c=b; c>=0; c-=50){
				for(int d=c; d>= 0; d-=20){
					for(int e=d; e>=0; e-=10){
						for(int f=e; f>=0; f-=5){
							for(int g=f; g>=0; g-=2){
								cout<<a<<":"<<b<<":"<<b<<":"<<c<<":"<<d<<":"<<e<<":"<<f<<":"<<g<<endl;
								combos++;
							}}}}}}}
	cout<<combos<<endl;	
	return 0;					
			
}
