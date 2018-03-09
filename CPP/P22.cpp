#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

std::string::iterator letter;

int getScore(std::string name, int number)
{
	int score = 0;
	for (int i = 0; i<name.size(); i++)
	{
	//	std::cout<<name[i]<<":" <<(int)name[i] - 64;
		score += (int) name[i] - 64;
	}
	score *= number;
	//std::cout<<number<<" " <<score<<"\n";
	return score;
}

int main()
{
	
	std::list<std::string> nameList;
	std::list<std::string>::iterator it;
	
	
	std::ifstream iFile("C:\\Users\\alexm\\Documents\\NamesP22.txt", std::ifstream::in);
	
	it = nameList.begin();
	
	int namecount = 0;
	
	// Read in list of names
	std::string text;
	std::string aName;
	iFile >> text;
	
	// Parse names into list
	std::stringstream in_string(text);
	while(std::getline(in_string,aName, '\"'))
	{
		if(aName != ",")
		{
		
		namecount++;
		std::cout<<aName<<" ";
		nameList.push_back(aName);
		}
	}
	
	
	// Alphabetize the list
	nameList.sort();
	//std::cout<<"\n\n"<<std::endl;
	//do
	//{
	//	it++;
	//	std::cout<<*it<<" ";
	//}	while(it != nameList.end());
	
	//std::cout<<"\nnames:"<<namecount;
	
	// Compute total score
	nameList.begin();
	it = nameList.begin();
	int namenum = 0;
	int score = 0;
	do
	{
		//std::cout<<"name: "<<*it<<std::endl;
		score += getScore(*it, namenum);
		std::cout<<score<<std::endl;
		namenum++;
		it++;
	}while(it!=nameList.end());
	std::cout<<"\n\nscore: "<<score<<std::endl;
	return 0;
}
