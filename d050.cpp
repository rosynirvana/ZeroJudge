#include <iostream>

int main()
{
	int h;
	while(std::cin >> h){
		if(h >= 15)
			std::cout << h - 15 << "\n";
		else
			std::cout << h + 9 << "\n";
	}
	return 0;
}