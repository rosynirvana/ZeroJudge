#include <iostream>
#include <ios>

int main()
{
	int n;
	while(std::cin >> n){
		std::cout << (n/12*50 + n%12*5);
	}
	return 0;
}