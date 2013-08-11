#include <iostream>

int main()
{
	int n;
	while(std::cin >> n){
		if(n == 0)
			break;

		for(int i=0; i<n; ++i)
			if(i%7 != 0)
				std::cout << i << " ";

		std::cout << "\n";
	}
}