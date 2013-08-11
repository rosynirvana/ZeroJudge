/* reading the whole input and then process is a two-pass method 
 * but read and process could involve more I/O so optimization calls
 * for profiling. This two-pass method got AC within 0.2 seconds and
 * eaten up 14.8MB RAM anyway. */
#include <iostream>
#include <ios>
#include <string>
#include <cstdio>

using std::cin;
using std::cout;
using std::string;

int main()
{
	std::ios_base::sync_with_stdio(false);

	unsigned int length;
	string input, result;
	char buf[10];

	while(cin >> length >> input){
		bool shorter = true;
		
		char currentChar = input[0];
		int num_currentChar = 1;
		for(size_t i=1; i!=length; ++i){
			if(input[i] != currentChar){
				sprintf(buf, "%d", num_currentChar);
				result.append(buf).push_back(currentChar);
				currentChar = input[i];
				num_currentChar = 1;
				if(result.size() >= length){
					shorter = false;
					break;
				}
			}
			else
				++num_currentChar;
		}
		if(shorter){
			sprintf(buf, "%d", num_currentChar);
			result.append(buf).push_back(currentChar);
			if(result.size() >= length)
				shorter = false;
		}
		
		if(shorter)
			cout << result << "\n\n";
		else
			cout << input << "\n\n";
	}

	return 0;
}