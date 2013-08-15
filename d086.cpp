#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string input;
	while(std::cin >> input && input.compare("0") != 0){
		int sum = 0;
		for(size_t i=0; i!=input.size(); ++i){
			if(isalpha(input[i]))
				sum += (toupper(input[i]) - 'A' + 1);
			else{
				sum = -1;
				break;
			}

		}
		if(sum != -1)
			std::cout << sum << "\n";
		else
			std::cout << "Fail\n";
	}
	return 0;
}