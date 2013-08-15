#include <iostream>

int main()
{
	int y;
	while(std::cin >> y){
		if((y%400 == 0) || ((y%4==0) && (y%100 != 0)))
			std::cout << "a leap year\n";
		else
			std::cout << "a normal year\n";
	}
	return 0;
}