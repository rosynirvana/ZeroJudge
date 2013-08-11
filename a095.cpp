#include <iostream>

int main()
{
	int N, M;
	while(std::cin >> N){
		std::cin >> M;
		if(M != N)
			std::cout << M+1 << "\n";
		else
			std::cout << M << "\n";
	}
	return 0;
}