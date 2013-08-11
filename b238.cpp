/* works but cannot get ACed */
#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	for(int i=0; i!=n; ++i){
		long long a,b,c,d,M;
		int day;
		std::cin >> a >> b >> c >> d >> day >> M;

		long long h = 1, t = 1;
		for(int j = 1; j <= day; ++j){
			long long lh = h, lt = t;
			t = (a * lt + b * lh) % M;
			h = (c * lt + d * lh) % M;
		}

		//std::cout << t << " " << h;

		if(t == h)
			std::cout << "Normal\n";
		else if(t > h)
			std::cout << "Tsundere\n";
		else
			std::cout << "Haraguroi\n";
	}
	return 0;
}