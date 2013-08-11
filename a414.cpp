#include <cstdio>

int main()
{
	int n;
	while(scanf("%d", &n) == 1 && n != 0){
		int ary[40];
		int pos = 0;
		while(n > 0){
			ary[pos++] = n % 2;
			n /= 2;
		}
		int upper = pos-1;
		pos = 0;
		
		int sum;
		if(ary[pos] == 0)
			sum = 0;
		else{
			sum = 1;
			++pos;
			bool carry = true;
			for(; pos <= upper; ++pos){
				if(carry == false || ary[pos] == 0)
					break;
				else
					++sum;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}

