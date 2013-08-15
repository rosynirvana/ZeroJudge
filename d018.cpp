#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
#include <string>

int main()
{
	std::string input;
	while(std::getline(std::cin, input) && input.size() != 0){
		std::stringstream buf(input);
		std::vector< std::pair<int, double> > pool;
		int seq;
		char sep;
		double num;
		while(buf >> seq >> sep >> num){
			//std::cout << seq << " " << num << "\n";
			pool.push_back(std::make_pair(seq, num));
		}

		double sum = 0;
		for(size_t i=0; i!=pool.size(); ++i)
			if(pool[i].first % 2 == 0)
				sum -= pool[i].second;
			else
				sum += pool[i].second;

		std::cout << sum <<"\n";
	}
	return 0;
}