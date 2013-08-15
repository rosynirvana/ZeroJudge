#include <iostream>

int main()
{
	int x;
	while(std::cin >> x){
		std::cout << (x ? 0 : 1);
	}
	return 0;
}