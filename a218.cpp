#include <iostream>
#include <ios>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstring>

bool comp(const std::pair<int, int>& p1, const std::pair<int, int>& p2)
{
	if(p1.second > p2.second)
		return true;

	if(p1.second == p2.second && p1.first < p2.first)
		return true;

	return false;
}

int main()
{
	int n;
	int count_pool[10];
	while(std::cin >> n){
		memset(count_pool, 0, sizeof(count_pool));
		for(int i=1; i<=n; ++i){
			int temp;
			std::cin >> temp;
			count_pool[temp] += 1;
		}
		std::vector< std::pair<int, int> > result_pool;
		for(int i=0; i!=10; ++i)
			if(count_pool[i] != 0)
				result_pool.push_back(std::make_pair(i, count_pool[i]));

		std::sort(result_pool.begin(), result_pool.end(), comp);

		for(size_t i=0; i!=result_pool.size(); ++i)
			std::cout << result_pool[i].first << " ";

		std::cout << "\n";
	}
}