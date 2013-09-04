#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

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
		std::sort(buf.begin(), buf.end());
		for(std::vector<int>::const_iterator iter = buf.begin();
			iter != buf.end(); ++iter)
			std::cout << *iter << " ";

		std::cout << "\n";
	}
	return 0;
}