#include <iostream>
#include <cstring>

void cal(int, int*, int (*)[3]);
void dump_pool(const int (*result_pool)[3])
{
	for(int i=0; i!=3; ++i){
		for(int j=0; j!=3; ++j)
			std::cout << result_pool[i][j] << " ";
			std::cout << "\n";
	}
	std::cout << "\n";
}

const int base_pool[3][3] = {{0,1,0}, {1,1,0}, {0,0,0}};

int main()
{
	int n;
	while(std::cin >> n){
		if(n == 1){
			std::cout << 1 << "\n";
			continue;
		}
		if(n == 2){
			std::cout << 2 << "\n";
			continue;
		}
		int buf[32];
		int pos = 0;
		n = n - 2;
		//std::cout << n << "\n";
		while(n > 1){
			if(n % 2 == 0)
				buf[pos] = 0;
			else
				buf[pos] = 1;
			++pos;
			n /= 2;
		}
		//std::cout << pos << "\n";
		int result_pool[3][3];
		cal(pos, buf, result_pool);

		std::cout << (1*result_pool[1][0] + 2*result_pool[1][1]) % 10007 <<"\n";
	}
}

void cal(int pos, int* buf, int (*result_pool)[3])
{
	int old_pool[3][3];
	memcpy(old_pool, base_pool, sizeof(base_pool));
	/*
	int temp = pos - 1;
	for(; temp >= 0; --temp)
		std::cout << buf[temp] << " ";
	std::cout << std::endl;
	*/
	int new_pool[3][3];

	for(pos = pos - 1; pos >= 0; --pos){
		if(buf[pos] == 1){
			for(int i=0; i!=3; ++i)
				for(int j=0; j!=3; ++j){
					new_pool[i][j] = 0;
					for(int k=0; k!=3; ++k)
						new_pool[i][j] += old_pool[i][k] * old_pool[k][j] % 10007;
				}

			memcpy(old_pool, new_pool, sizeof(old_pool));

			for(int i=0; i!=3; ++i)
				for(int j=0; j!=3; ++j)
					for(int k=0; k!=3; ++k){
						new_pool[i][j] = 0;
					for(int k=0; k!=3; ++k)
						new_pool[i][j] += old_pool[i][k] * base_pool[k][j] % 10007;
				}
			memcpy(old_pool, new_pool, sizeof(old_pool));
		}
		else{
			for(int i=0; i!=3; ++i)
				for(int j=0; j!=3; ++j)
					for(int k=0; k!=3; ++k){
						new_pool[i][j] = 0;
					for(int k=0; k!=3; ++k)
						new_pool[i][j] += old_pool[i][k] * old_pool[k][j] % 10007;
				}
			memcpy(old_pool, new_pool, sizeof(old_pool));
		}
	}

	memcpy(result_pool, old_pool, sizeof(old_pool));	

	//dump_pool(result_pool);
}