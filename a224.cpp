#include <iostream>
#include <cctype>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::string;
using std::map;

int main()
{
	string input;
	while(std::cin >> input){
		map<char, int> temp;
		string::const_iterator iter;
		for(iter = input.begin(); iter != input.end(); ++iter)
			if(isalpha(*iter)){
				if(temp.find(toupper(*iter)) == temp.end())
					temp[toupper(*iter)] = 1;
				else
					++temp[toupper(*iter)];
			}
		
		int odd = 0;
		for(map<char, int> :: const_iterator miter = temp.begin(); miter != temp.end(); ++miter){
			if((miter ->second) % 2 != 0)
				++odd;
			if(odd > 1)
				break;
		}

		if(odd > 1)
			cout << "no...\n";
		else
			cout << "yes !\n";
	}
	return 0;
}