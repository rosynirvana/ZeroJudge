#include <iostream>
#include <ios>

int main()
{
	std::ios_base::sync_with_stdio(false);

	long long int a, b, c;
	char result;
	while(std::cin >> a >> b >> c){
		if(a > b && b >= c){
			if(b + c > a)
				result = 'B';
			else
				result = 'A';
		}
		else if(a > c && c >= b){
			if(b + c > a)
				result = 'C';
			else
				result = 'A';
		}
		else if(b > a && a >= c){
			if(a + c > b)
				result = 'A';
			else
				result = 'B';
		}
		else if(b > c && c >= a){
			if(a + c > b)
				result = 'C';
			else
				result = 'B';
		}
		else if(c > b && b >= a){
			if(b + a > c)
				result = 'B';
			else
				result = 'C';
		}
		else if(c > a && a >= b){
			if(b + a > c)
				result = 'A';
			else
				result = 'C';
		}
		std::cout << result << "\n";
	}
	return 0;
}