#include <iostream>
#include <sstream>
#include <string>
#include <ios>

void cal(std::string&, const std::string&, bool);

int main()
{
	std::string input;
	std::ios_base::sync_with_stdio(false);

	while(std::getline(std::cin, input)){
		std::stringstream buf(input);
		std::string result;
		buf >> result;
		std::string temp;
		bool isNum = false;
		bool opIsAnd = true;
		std::cout << result;
		while(buf >> temp){
			if(isNum){
				std::cout << temp;
				if(opIsAnd)
					cal(result, temp, true);
				else
					cal(result, temp, false);
				isNum = false;
			}
			else{
				if(temp.compare("or") == 0){
					std::cout << "||";
					opIsAnd = false;
				}
				else if(temp.compare("and") == 0){
					std::cout << "&&";
					opIsAnd = true;
				}
				isNum = true;
			}
		}
		std::cout << " = " << result << "\n";
	}
	return 0;
}

void cal(std::string& result, const std::string& temp, bool opIsAnd)
{
	if(opIsAnd)
		for(size_t i=0; i!=5; ++i)
			result[i] = ((result[i] - '0') & (temp[i] - '0')) + '0';
	else
		 for(size_t i=0; i!=5; ++i)
			result[i] = ((result[i] - '0') | (temp[i] - '0')) + '0';
}