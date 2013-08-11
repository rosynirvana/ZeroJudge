/*WARNING : MAY NOT GET THE CORRECT ANSWER UNDER mingw
 *If you want to fix it manually, see comments in cmath */
#include <iostream>
#include <vector>
#include <cmath>


bool cal(int, int);

int main()
{
	//std::cout << static_cast<int>(pow(5,3));
	//std::cout << cal(153,3) <<"\n";

	int upper, lower;
	while(std::cin >> lower){
		std::cin >> upper;
		std::vector<int> buf;
		int n = 0, temp = lower;
		while(temp > 0){
			++n;
			temp /= 10;
		}
		while(lower < upper){
			if(cal(lower, n))
				buf.push_back(lower);
			++lower;
			if(lower == 10 || lower == 100 || lower == 1000 || lower == 10000 || lower == 100000 || lower == 1000000)
				++n;
		}
		if(buf.size() == 0)
			std::cout << "none" << "\n";
		else{
			for(std::vector<int>::const_iterator iter = buf.begin(); iter != buf.end(); ++iter)
				std::cout << *iter << " ";
			std::cout << "\n";
		}
	}
	return 0;
}

bool cal(int num, int n)
{
	int sum = 0, temp = num;
	while(temp > 0){
		//std::cout << (pow(temp%10, n)) << "\n";
		sum += (pow(temp%10, n));
		//std::cout << sum << "\n";
		temp /= 10;
	}
	//std::cout << "sum: " << sum << " num: " << num ;
	if(sum == num)
		return true;
	return false;
}