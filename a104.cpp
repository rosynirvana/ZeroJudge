#include <iostream>
#include <algorithm>

int main()
{
	int n;
	while(std::cin >> n){
		int a[1000];
		for(int i=0; i<n; ++i)
			std::cin >> a[i];
		std::sort(&a[0], (a+n));
		for(int i=0; i<n; ++i)
			std::cout << a[i] << " ";

		std::cout << "\n";
	}
	return 0;
}