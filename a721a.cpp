#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>

int main(int argc, char const *argv[])
{
	int T;
	std::ios::sync_with_stdio(false);
	std::cin >> T;
	for(int i=0; i!=T; ++i){
		int M, N;
		std::cin >> M >> N;
		std::vector<int> buf;
		for(int j=0; j!=M; ++j){
			int temp;
			std::cin >> temp;
			buf.push_back(temp);
		}
		std::sort(buf.begin(), buf.end());
		if(N > buf.back())
			std::cout << "not yet\n";
		else{
			size_t z;
			size_t limit = buf.size();
			for(z=0; z!=limit; ++z)
				if(buf[z] >= N)
					break;
			std::cout << (z+1)*50 << "\n";
		}
	}
	return 0;
}