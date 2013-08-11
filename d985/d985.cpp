#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);
	int N;
	std::cin >> N;
	for(int i=1; i<=N; ++i){
		int M;
		std::cin >> M;

		int sum = 0, min = 99999;
		for(int j=0; j!=M; ++j){
			int m, s;
			std::cin >> m >> s;
			s += m * 60;
			sum += s;
			if(s < min)
				min = s;
		}
		std::cout << "Track " << i << ":\n";
		std::cout << "Best Lap: " << min/60 << " minute(s) " << min%60 << " second(s).\n";
		std::cout << "Average: " << sum/M/60 << " minute(s) " << sum/M%60 << " second(s).\n\n";	
	}
	return 0;
}