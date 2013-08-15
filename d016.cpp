#include <iostream>
#include <ios>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>

int main()
{
	std::string input;
	while(std::getline(std::cin, input) && input.size() != 0){
		std::stringstream buf(input);
		std::string temp;
		std::stack<int> pool;
		while(buf >> temp){
			if(isdigit(temp.c_str()[0]))
				pool.push(atoi(temp.c_str()));
			else{
				int a = pool.top();
				pool.pop();
				int b = pool.top();
				pool.pop();

				char c = temp.c_str()[0];
				int result;
				switch(c){
					case '+':
					result = a+b;
					break;
					case '-':
					result = b-a;
					break;
					case '*':
					result = a*b;
					break;
					case '/':
					result = b/a;
					break;
					case '%':
					result = b%a;
					break;
				}
				pool.push(result);
			}
		}
		std::cout << pool.top() << "\n";
	}
	return 0;
}