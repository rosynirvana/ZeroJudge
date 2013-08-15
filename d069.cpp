#include <iostream>

int main()
{
	int x;
	std::cin >> x;
	for(int i=1; i<=x; ++i){
		int y;
		std::cin >> y;
		if((y%400 == 0) || ((y%4==0) && (y%100 != 0)))
			std::cout << "a leap year\n";
		else
			std::cout << "a normal year\n";
	}
	return 0;
}