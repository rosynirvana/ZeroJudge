#include <iostream>
#include <ios>
#include <cstdlib>

inline bool isLeapYear(int);
inline int daysPassed(int, int ,int);

int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	std::ios_base::sync_with_stdio(false);

	int y1, m1, d1;
	while(std::cin >> y1 >> m1 >> d1){
		int y2, m2, d2;
		std::cin >> y2 >> m2 >> d2;

		int sum = 0;
		if(y1 < y2){
			for(int y=y1; y<y2; ++y){
				sum += (isLeapYear(y) ? 366 : 365);
			}

			sum += (daysPassed(y2, m2, d2) - daysPassed(y1, m1, d1));
		}
		else if(y1 > y2){

			for(int y=y2; y<y1; ++y){
				sum += (isLeapYear(y) ? 366 : 365);
			}

			sum += (daysPassed(y1, m1, d1) - daysPassed(y2, m2, d2));
		}
		else{
			//std::cout << daysPassed(y1, m1, d1) << "\n";
			//std::cout << daysPassed(y2, m2, d2) << "\n";
			sum = abs(daysPassed(y1, m1, d1) - daysPassed(y2, m2, d2));
		}
		std::cout << sum << "\n";
	}
}

bool isLeapYear(int year)
{
	if(year % 400 == 0)
		return true;

	if(year % 4 == 0 && year % 100 != 0)
		return true;

	return false;
}

int daysPassed(int y, int m, int d)
{
	int days = 0;
	for(int i=0; i<m-1; ++i)
		days += month[i];

	if(isLeapYear(y) && m >= 3)
		days += 1;

	return days+d;
}