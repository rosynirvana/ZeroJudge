#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int w;
	while(std::cin >> w){
		if(w > 50)
			w -= 1;
		std::cout << w << "\n"; 
	}
	return 0;
}