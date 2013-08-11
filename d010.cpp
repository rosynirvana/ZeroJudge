#include <cstdio>
#include <vector>
#include <cmath>

using std::vector;

int main()
{
	int n;
	while(scanf("%d", &n) == 1){
		if(n == 1)
			printf("虧數\n");
		else{
		vector<int> buf;
		buf.push_back(1);
		int upper = static_cast<int>(sqrt(n));

		for(int i=2; i<upper; ++i)
			if(n % i == 0){
				buf.push_back(n/i);
				buf.push_back(i);
			}
		if(n % upper == 0){
			buf.push_back(upper);
			if(n / upper != upper)
				buf.push_back(n / upper);
		}

		for(vector<int>::const_iterator iter = buf.begin(); iter != buf.end();
			++iter){
			n -= *iter;
			if(n < 0)
				break;
		}

		if(n > 0)
			printf("虧數\n");
		else if(n == 0)
			printf("完全數\n");
		else
			printf("盈數\n");
	}
	}
	return 0;
}