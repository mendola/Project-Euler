#include <iostream>

using namespace std;

class date{

	public:
	int dayOfWeek;
	int dayOfMonth;
	int month;
	int year;
	date()
	{
	dayOfWeek = 1;
	dayOfMonth = 1;
	month = 1;
	year = 1900;
	}
	
	void getNextDay()
	{
		this->dayOfWeek = (this->dayOfWeek + 1) % 7;
		int temp = this->month;
		switch (this->month)
		{
			case 1: 
			{
				this->nextDay(31);
				break;
			}
			case 2:
			{
				if(( (this->year % 4 ==0) && (this->year % 100 != 0)) || (this->year % 400 == 0))
				{
					this->nextDay(29);
					break;
				}
				else
				{
					this->nextDay(28);
					break;
				}
				
			}
			case 3:
			{
				this->nextDay(31);
				break;
			}
			case 4:
			{
				this->nextDay(30);
				break;
			}
			case 5:
			{
				this->nextDay(31);
				break;
			}
			case 6:
			{
				this->nextDay(30);
				break;
			}
			case 7:
			{
				this->nextDay(31);
				break;
			}
			case 8:
			{
				this->nextDay(31);
				break;
			}
			case 9:
			{
				this->nextDay(30);
				break;
			}
			case 10:
			{
				this->nextDay(31);
				break;
			}	
			case 11:
			{
				this->nextDay(30);
				break;
			}
			case 12:
			{
				this->nextDay(31);
				break;
			}
				
		}
		
		//cout<<"day of week: "<<this->dayOfWeek<< "  day of month: "<<this->dayOfMonth<< "    month: "<< this->month <<"   year: "<<this->year<<endl;
	}	
	
	void nextDay(int monthLength)
	{
		if(this->dayOfMonth == monthLength)
		{
			this->dayOfMonth = 1;
			if(this->month == 12)
				{
					this->month = 1;
					this->year++;
				}
			else this->month = this->month + 1;
		}
		else
		{
			this->dayOfMonth = this->dayOfMonth + 1;
		}
	}
	
};



int main ()
{
	cout << "Working...\n\n";
	int countSundays = 0;
	date today;
	
	
	while(today.year != 2001)
	{
		today.getNextDay();
		if((today.dayOfWeek == 0) && (today.year >= 1901) && (today.dayOfMonth ==1))
		{
			countSundays++;
		}
		
	}
	
	cout<< countSundays<< " Sundays fell on the 1st of the month\n"<<endl;
	return 0;
}
