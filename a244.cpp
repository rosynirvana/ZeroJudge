#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	for(int i=0; i<N; ++i){
		long long int a, b, c;
		long long int d;
		std::cin >> a >> b >> c;
		switch(a){
		case 1:
		d = b + c;
		break;
		case 2:
		d = b - c;
		break;
		case 3:
		d = b * c;
		break;
		case 4:
		d = b / c;
		break;
		}
		std::cout << d << "\n";
	}
	return 0;
}