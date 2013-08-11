#include <iostream>

int main()
{
	int n;
	while(std::cin >> n){
		int score;
		if(n<=10)
			score = 6*n;
		else if(n<=20)
			score = 60 + (n-10)*2;
		else if(n<=40)
			score = 80 + n - 20;
		else
			score = 100;

		std::cout << score << "\n";
	}
	return 0;
}