#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n, m;
	int food[500][500];
	while(std::cin >> n >> m){
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				std::cin >> food[i][j];

		
		for(int i=1; i<n; ++i)
			food[0][i] += food[0][i-1];
		for(int i=1; i<n; ++i)
			food[i][0] += food[i-1][0];

		for(int i=1; i<n; ++i)
			for(int j=1; j<n; ++j)
				food[i][j] = food[i][j] + food[i-1][j] + food[i][j-1] - food[i-1][j-1];


		for(int i=0; i!=m; ++i){
			int x1, y1, x2, y2;
			std::cin >> x1 >> y1 >> x2 >> y2;
			int sum = 0;
			if(x1 == 1 && y1 == 1)
				sum = food[x2-1][y2-1];
			else if(x1 == 1)
				sum = food[x2-1][y2-1] - food[x2-1][y1-2];
			else if(y1 == 1)
				sum = food[x2-1][y2-1] - food[x1-2][y2-1];
			else
				sum = food[x2-1][y2-1] + food[x1-2][y1-2] - food[x1-2][y2-1] - food[x2-1][y1-2];

			std::cout << sum << "\n";
		}
	}
	return 0;
}