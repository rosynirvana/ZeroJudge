#include <iostream>

int main()
{
	int x;
	while(std::cin >> x){
		if(x > 0)
			std::cout << 1 << "\n";
		else if(x == 0)
			std::cout << 0 << "\n";
		else
			std::cout << -1;
	}
	return 0;
}