#include <iostream>
#include <ios>

int main()
{
	int alpha[] = {10, 11, 12, 13, 14, 15 ,16, 17, 34, 18, 19, 20,
					21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30,
						31, 33};
	std::ios_base::sync_with_stdio(false);
	for(int i=0; i != 26; ++i)
		alpha[i] = alpha[i] / 10 + alpha[i] % 10 * 9;

	std::string input;
	while(std::cin >> input){
		int num = 0;
		for(int i=0; i != 8; ++i){
			num += (8-i) * (input[i] - '0');
			//std::cout << num << '\n';
		}
		num += (input[8] - '0');
		//std::cout <<"\n" << num << '\n';
		for(int i=0; i!=26; ++i)
			if((alpha[i] + num) % 10 == 0)
				std::cout << static_cast<char>(i+'A');
		std::cout << "\n";
	}
	return 0;
}