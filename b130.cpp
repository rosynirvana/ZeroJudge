#include <cstdio>
#include <bitset>

using std::bitset;

int main()
{
	int M;
	while(scanf("%d", &M) == 1){
		bitset<1000> buf;
		int min = 1001;
		int max = -1;
		int count = 0;
		for(int i=0; i!=M; ++i){
			int temp;
			scanf("%d", &temp);
			if(buf[temp-1] != 1){
				buf[temp-1] = 1;
				++count;
			}
			if(temp < min)
				min = temp-1;
			if(temp > max)
				max = temp-1;
		}
		printf("%d\n", count);
		for(; min<=max; ++min)
			if(buf[min] == 1)
				printf("%d ", min+1);

		printf("\n");
	}
	return 0;
}