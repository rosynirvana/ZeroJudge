#include <iostream>
#include <string>

int main()
{
	std::string input;
	while(std::cin >> input){
		for(int i=1; i!=7; ++i)
			std::cout << (input[i] > input[i-1] ? input[i] - input[i-1] : input[i-1] - input[i]);
		std::cout << "\n";
	}
	return 0;
}