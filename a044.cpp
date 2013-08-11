#include <iostream>

int main()
{
	int n;
	while(std::cin >> n){
		
		std::cout << (n*n*n + 5 * n + 6) / 6 << "\n";
	}

	return 0;
}