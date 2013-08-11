#include <iostream>
#include <ios>
#include <cstdlib>

int main()
{
	int T;
	std::ios_base::sync_with_stdio(false);
	std::cin >> T;
	for(int i=0; i!=T; ++i){
		int N;
		std::cin >> N;
		//std::cout << N << "\n";
		int t_left = 0, t_right = 0;
		int current_pos = 0;
		for(int j=0; j!=N; ++j){
			int temp;
			int next_pos;
			std::cin >> temp;
			//std::cout << temp << "\n";
			next_pos = current_pos + temp;
			if(next_pos >= 0 && current_pos >= 0)
				t_right += abs(temp);
			else if(next_pos <= 0 && current_pos <= 0)
				t_left += abs(temp);
			else if(current_pos < 0 && next_pos > 0){
				t_left -= current_pos;
				t_right += next_pos;
			}
			else if(current_pos > 0 && next_pos < 0){
				t_right += current_pos;
				t_left -= next_pos;
			}
			current_pos = next_pos;
			//std::cout << t_left << " " << t_right << "\n";
		}
		if(t_left == t_right)
			std::cout << "Both okay\n";
		else if(t_left < t_right)
			std::cout << "Go right\n";
		else
			std::cout << "Go left\n";
	}
	return 0;
}