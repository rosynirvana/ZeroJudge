#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	int max = -1;
	for(int i=0; i<n; ++i){
		int temp;
		std::cin >> temp;
		if(temp > max)
			max = temp;
	}

	std::cout << max << "\n";
	return 0;
}