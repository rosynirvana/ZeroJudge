#include <iostream>
#include <ios>
#include <cstdio>

int count2(int);

int main()
{
	std::ios_base::sync_with_stdio(false);
	int L, R;
	while(std::cin >> L >> R){
		int count = 0;
		for(; L<=R; ++L)
			count += count2(L);

		std::cout << count << "\n";
	}
	return 0;
}

int count2(int num)
{
	int result = 0;
	char buf[10];
	sprintf(buf, "%d", num);
	for(int i=0; buf[i] != '\0'; ++i)
		if(buf[i] == '2')
			++result;

	return result;
}