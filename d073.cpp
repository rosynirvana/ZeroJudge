#include <iostream>

int main()
{
	int n;
	while(std::cin >> n){
		if(n % 3 == 0)
			std::cout << n/3 << "\n";
		else
			std::cout << n/3+1 << "\n";
	}
	return 0;
}