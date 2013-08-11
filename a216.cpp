#include <iostream>

long long int f[30000] = {1};
long long int g[30000] = {1};

int main()
{
	for(int i=1; i<30000; ++i){
		f[i] = i + 1 + f[i-1];
		g[i] = f[i] + g[i-1];
	}

	int n;
	while(std::cin >> n){
		std::cout << f[n-1] << " " << g[n-1] << "\n";
	}

	return 0;
}