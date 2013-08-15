#include <iostream>
#include <ios>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int temp[20000000];

int main()
{
	vector<int> prime_table;
	
	for(int i=1; i<=20000000; ++i)
		temp[i] = i;

	temp[0] = 0;
	temp[1] = 0;
	
	int upper = 4473;
	while(true){
		int i = 2;
		while(true){
			if(temp[i] != 0)
				break;
			else
				++i;
		}
		if(temp[i] > upper)
			break;
		prime_table.push_back(temp[i]);
		for(int j = i; j < 20000000; j += i)
			temp[j] = 0;
	}

	for(int i=0; i<20000000; ++i)
		if(temp[i] != 0)
			prime_table.push_back(i);
		/*
	for(int i=prime_table.back(); prime_table.back() <= 20000000; i+=2){
		bool isP = true;
		for(size_t j=0; j != prime_table.size() && prime_table[j] * prime_table[j] <= i; ++j)
			if(i % prime_table[j] == 0){
				isP = false;
				break;
			}
		if(isP)
			prime_table.push_back(i);
	}
	*/

	vector<int> result;
	for(size_t i=0; result.size() <= 100000; ++i)
		if(prime_table[i+2] - prime_table[i] == 4 ||
			prime_table[i+1] - prime_table[i] == 4)
			result.push_back(prime_table[i]);

	int S;
	while(std::cin >> S){
		std::cout << "(" << result[S-1] << ", " << result[S-1] + 4 << ")\n";
	}
	return 0;
}