#include <cstdio>

int main()
{
	int n;
	while(scanf("%d", &n) == 1){
		int result[3] = {0};
		for(int i=0; i<n; ++i){
			int temp;
			scanf("%d", &temp);
			++result[temp%3];
		}
		printf("%d %d %d\n", result[0], result[1], result[2]);
	}
	return 0;
}