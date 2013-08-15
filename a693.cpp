#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n, m;
	int food[100000];

	while(std::cin >> n >> m){
		for(int i=0; i<n; ++i)
			std::cin >> food[i];
		for(int i=1; i<n; ++i)
			food[i] += food[i-1];


		for(int i=0; i<m; ++i){
			int sum = 0;
			int begin, end;
			std::cin >> begin >> end;
			if(begin == 1)
				sum = food[end-1];
			else
				sum = food[end-1] - food[begin-2];
			std::cout << sum << "\n";
		}
	}
	return 0;
}