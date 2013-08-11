/* This works but cannot get ACed */

#include <iostream>

int main()
{
	int buf[50000];
	buf[0] = 1, buf[1] = 2;
	for(int i=2; i != 50000; ++i)
		buf[i] = (buf[i-1] + buf[i-2]) % 10007;
	int n;
	while(std::cin >> n){
		if(n <= 50000)
			std::cout << buf[n-1] <<"\n";
		else{
			int a, b, c, k;
			a = buf[49998];
			b = buf[49999];
			k = 50001;
			while(k <= n){
				c = a;
				a = (a + b + 1) % 10007;
				b = c;
				++k;
			}
			std::cout << a << "\n";
		}
	}
	return 0;
}