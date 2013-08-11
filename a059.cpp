#include <cstdio>
#include <cmath>

int main()
{
	int t;
	scanf("%d", &t);

	for(int i=0; i<t; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		int lower = static_cast<int>(ceil(sqrt(a)));
		int upper = static_cast<int>(floor(sqrt(b)));
		int sum = 0;
		for(; lower<=upper; ++lower)
			sum += lower * lower;
		printf("Case %d: %d\n", i+1, sum);
	}
	return 0;
}