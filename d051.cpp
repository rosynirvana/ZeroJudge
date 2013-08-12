#include <iostream>
#include <ios>
#include <iomanip>

int main()
{
	std::ios_base::sync_with_stdio(false);

	std::cout << std::fixed << std::setprecision(3);

	int f;
	while(std::cin >> f){
		double c;
		c = (f-32)/9.0*5;
		std::cout << c;
	}
	return 0;
}