#include <cstdio>

int gcd(long long, long long);

int main()
{
	long long a ,b;
	while(scanf("%lld %lld", &a, &b) == 2)
		printf("%d\n", gcd(a, b));
}

int gcd(long long a, long long b)
{
	while(a!=0 && b!=0){
		if(a >= b)
			a = a % b;
		else
			b = b % a;
	}
	if(a == 0)
		return (int)b;
	
	return (int)a;
}