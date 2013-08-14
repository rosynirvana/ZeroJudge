#include <iostream>

int main()
{
	int m;
	while(std::cin >> m){
		if(25 - m >= 0)
			std::cout << 25 - m << "\n";
		else
			std::cout << 85 - m << "\n";
	}
	return 0;
}