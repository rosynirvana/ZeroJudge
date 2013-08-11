#include <iostream>
#include <ios>

int main()
{
	double k;
	while(std::cin >> k){
		double sum = 1;
		double i = 2;
		while(sum <= k){
			sum += 1/i;
			++i;
		}
		std::cout << static_cast<int>(i-1) << "\n";
	}
	return 0;
}