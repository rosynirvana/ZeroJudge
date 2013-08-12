#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int n, k;
	while(std::cin >> n >> k){
		bool c = true;
		if(n != 0){
			if(k > n)
				c = false;
			else if(k == 0)
				c = false;
			else if(n % k != 0)
				c = false;
		}

		if(c)
			std::cout << "Ok!\n";
		else
			std::cout << "Impossib1e!\n";
	}
	return 0;
}