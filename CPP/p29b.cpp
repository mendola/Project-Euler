#include <iostream>
#include <math.h>
#include <set>

	std::set<float> mySet;
	std::pair<std::set<float>::iterator,bool> ret;
	std::set<float>::iterator it;
	
	int count = 0;
	
int addToList(float num)
{
	ret = mySet.insert(num);
	if(ret.second == true)
		{
		count++;
		return 1;
		}
	else return 0;
						
}

void printSet()
{
	for(it=mySet.begin(); it!=mySet.end(); ++it)
	{
		std::cout<<" " << *it;
	}
	std::cout<<"\ncount: "<<count<<std::endl;
}


int main()
{

	
	for (int a=2; a<=100; a++)
	{
		for (int b=2; b<=100; b++)
		{
			float num = pow(b,a);
			int inserted = addToList(num);
			if(inserted==1)
				count++;
		}
	}
	std::cout<<"count: "<<count<<std::endl;

	return 0;
}
