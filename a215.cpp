#include <cstdio>

int main()
{
	int a, b;
	while(scanf("%d %d", &a, &b) == 2){
		int sum = 0;
		int a0 = a;
		for(; ; ++a){
			sum += a;
			if(sum > b)
				break;
		}
		printf("%d\n", a - a0 + 1);
	}
	return 0;
}