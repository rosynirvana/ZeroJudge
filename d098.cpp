#include <iostream>
#include <ios>
#include <sstream>
#include <string>
#include <cstdlib>

int main()
{
	std::string input;
	while(std::getline(std::cin, input) && input.size() != 0){
		std::stringstream buf(input);
		int sum = 0;
		std::string temp;
		while(buf >> temp){
			bool isNum = true;
			for(size_t i=0; i!=temp.size(); ++i)
				if(!isdigit(temp[i])){
					isNum = false;
					break;
				}
			if(isNum)
				sum += atoi(temp.c_str());
		}
		std::cout << sum << "\n";
	}
	return 0;
}