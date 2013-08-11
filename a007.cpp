#include <cstdio>
#include <vector>
#include <algorithm>

using std::binary_search;
using std::vector;

bool isPrime(int n, vector<int>&);

int main()
{
	int n, m;
	vector<int> prime_table;
	int temp[46369];
	for(int i=1; i<=46368; ++i)
		temp[i] = i;

	temp[0] = 0;
	temp[1] = 0;
	
	int upper = 216;
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
		for(int j = i; j < 46369; j += i)
			temp[j] = 0;
	}

	for(int i=0; i<46369; ++i)
		if(temp[i] != 0)
			prime_table.push_back(i);

	while(scanf("%d %d", &n, &m) == 2){
		int sum = 0;
		for(; n<=m; ++n)
			if(isPrime(n, prime_table))
				++sum;

		printf("%d\n", sum);
	}

	return 0;
}

bool isPrime(int n, vector<int>& prime_table)
{
	if(n <= prime_table.back()){
		if(binary_search(prime_table.begin(), prime_table.end(), n))
			return true;
		else
			return false;
	}
	else{
		for(vector<int>::const_iterator iter = prime_table.begin();
			iter != prime_table.end() && *iter * *iter <= n; ++iter)
			if(n % *iter == 0)
				return false;
		}
		return true;
}