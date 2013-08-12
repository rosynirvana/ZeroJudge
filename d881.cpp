#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int buf[50] = {1};
	int d;
	while(std::cin >> d){
		int t = d;
		d = 1;
		for(int i=1; i!=50; ++i, d += t)
			buf[i] = buf[i-1] + d;

		int sum = 0;
		for(int i=0; i!=50; ++i)
			sum += buf[i];

		std::cout << sum << "\n";
	}
	return 0;
}