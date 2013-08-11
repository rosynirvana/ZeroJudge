#include <map>
#include <iostream>
#include <ios>
#include <string>
#include <utility>
#include <cctype>
#include <cstdlib>
#include <vector>

void parseInput(const std::string& comp, std::vector< std::pair< std::string, int > >& buf);

int main()
{
	std::ios::sync_with_stdio(false);

	int M, N;
	while(std::cin >> M >> N){
		std::map< std::string, int > table;
		for(int i=0; i != M; ++i){
			std::string tstring;
			int temp;
			std::cin >> tstring >> temp;
			table[tstring] = temp;
		}

		for(int i=0; i != N; ++i){
			std::string comp;
			std::cin >> comp;
			std::vector< std::pair< std::string, int > > buf;
			parseInput(comp, buf);
			int sum = 0;
			for(size_t j=0; j!=buf.size(); ++j)
				sum += table[buf[j].first] * buf[j].second;
			std::cout << sum << "\n";	
		}
	}
	return 0;
}

void parseInput(const std::string& comp, std::vector< std::pair< std::string, int > >& buf)
{
	size_t left = 0, right = 0;
	std::vector< std::string > minibuf;
	while(right != comp.size()){
		if(isupper(comp[right])){
			minibuf.push_back(comp.substr(left, right - left));
			left = right;
			++right;
		}
		else
			++right;
	}
	minibuf.push_back(comp.substr(left, right - left));
	for(size_t i=0; i != minibuf.size(); ++i){
		if(isdigit(minibuf[i][minibuf[i].size()-1])) {
			if(isdigit(minibuf[i][1])){
				int num = atoi(minibuf[i].substr(1).c_str());
				buf.push_back(make_pair(minibuf[i].substr(0,1), num));
			}
			else{
				int num = atoi(minibuf[i].substr(2).c_str());
				buf.push_back(std::make_pair(minibuf[i].substr(0,2), num));
			}
		}
		else
			buf.push_back(std::make_pair(minibuf[i], 1));
	}
}