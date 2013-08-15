#include <iostream>

int main()
{
	int a, b, c;
	while(std::cin >> a >> b >> c){
		int max = (a > b ? a : b);
		std::cout << (max > c ? max : c) << "\n";
	}
	return 0;
}