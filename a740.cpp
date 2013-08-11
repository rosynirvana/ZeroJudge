#include <cstdio>
#include <vector>

using std::vector;

int main()
{
	int n;
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

	while(scanf("%d", &n) == 1){
		vector<int> result;
		while(n > 1){
			bool premature = false;
			for(vector<int>::const_iterator iter = prime_table.begin();
				iter != prime_table.end() && *iter * *iter <= n; ++iter)
				if(n % *iter == 0){
					result.push_back(*iter);
					n /= *iter;
					premature = true;
					break;
				}

			if(!premature){
				result.push_back(n);
				n = 1;
			}
		}

		int sum = 0;
		for(vector<int>::const_iterator iter = result.begin();
			iter != result.end(); ++iter)
			sum += *iter;
		printf("%d\n", sum);
	}
	return 0;
}