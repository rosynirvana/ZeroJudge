#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::vector;
using std::sort;
using std::pair;
using std::make_pair;

bool comp(const pair<char, int>& p1, const pair<char, int>& p2)
{
	if(p1.second < p2.second)
		return false;
	if(p1.second == p2.second){
		if(p1.first == '>')
			return true;
		if(p2.first == '>')
			return false;
		if(p1.first == '=')
			return true;
		if(p2.first == '=')
			return false;
	}
	return true;
}

int main()
{
	int n;
	while(cin >> n && n != 0){
		long long int a, b;
		vector< pair<char, long long int> > buf;
		for(int i=0; i!=n; ++i){
			cin >> a >> b;
			long long int c = a + b;
			if(a > b)
				buf.push_back(make_pair('>', c));
			else if(a == b)
				buf.push_back(make_pair('=', c));
			else
				buf.push_back(make_pair('<', c));
		}

		sort(buf.begin(), buf.end(), comp);
		for(size_t i=0; i != buf.size(); ++i)
			std::cout << buf[i].first << buf[i].second << " ";

		std::cout << "\n";
	}
	return 0;
}