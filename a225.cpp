#include <iostream>
#include <algorithm>
#include <vector>

bool comp(int i, int j);

int main()
{
	int n;
	while(std::cin >> n){
		std::vector<int> buf;
		for(int i=0; i!=n; ++i){
			int temp;
			std::cin >> temp;
			buf.push_back(temp);
		}
		std::sort(buf.begin(), buf.end(), comp);
		for(std::vector<int>::const_iterator iter = buf.begin(); iter != buf.end(); ++iter)
			std::cout << *iter << " ";
		std::cout << "\n";
	}
	return 0;
}

bool comp(int i, int j)
{
	if(i % 10 < j % 10)
		return true;
	if(i % 10 > j % 10)
		return false;
	if(i / 10 > j / 10)
		return true;
	return false;
}