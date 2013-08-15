#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

int main()
{
	int a, b;
	while(std::cin >> a >> b){
		std::cout << static_cast<int>(pow(a, b)) << "\n";
		std::cin >> a;
		std::cout << std::setprecision(3) << std::fixed;
		std::cout << sqrt(a) << "\n";
		std::cin >> a;
		std::cout << abs(a) << "\n";
		std::cin >> a >> b;
		srand(time(0));

		std::cout << rand() %(b-a) + a << "\n";
	}
	return 0;
}