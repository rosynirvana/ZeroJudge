#include <iostream>
#include <cstring>

void normalize(long long int (*result_pool)[2], int M)
{
	for(int i=0; i!=2; ++i)
		for(int j=0; j!=2; ++j)
			result_pool[i][j] = (result_pool[i][j] + M) % M;
}
void dump_pool(long long int (*result_pool)[2])
{
	for(int i=0; i!=2; ++i){
		for(int j=0; j!=2; ++j)
			std::cout << result_pool[i][j] << " ";
			std::cout << "\n";
	}
	std::cout << "\n";
}

void cal(int, int*, long long int (*)[2], long long int (*)[2], int);

int main()
{
	int n;
	std::cin >> n;
	for(int i=0; i!=n; ++i){
		long long a,b,c,d,M;
		int day;
		std::cin >> a >> b >> c >> d >> day >> M;

		if(day != 0){
			long long int base_pool[2][2] = {{a, b}, {c, d}};
			//dump_pool(base_pool);
			int buf[32];
			int pos = 0;
			while(day > 1){
				if(day % 2 == 0)
					buf[pos++] = 0;
				else
					buf[pos++] = 1;
				day /= 2;
			}
			long long int result_pool[2][2];
			cal(pos, buf, result_pool, base_pool, M);

			if((a + b) % M == (c + d) % M)
				std::cout << "Normal\n";
			else if((a + b) % M > (c + d) % M)
				std::cout << "Tsundere\n";
			else
				std::cout << "Haraguroi\n";
		}
		else
			std::cout << "Normal\n";
	}
	return 0;
}

void cal(int pos, int* buf, long long int (*result_pool)[2], long long int (*base_pool)[2], int M)
{
	long long int old_pool[2][2];
	memcpy(old_pool, base_pool, sizeof(base_pool));
	/*
	int temp = pos - 1;
	for(; temp >= 0; --temp)
		std::cout << buf[temp] << " ";
	std::cout << std::endl;
	*/
	long long int new_pool[2][2];

	for(pos = pos - 1; pos >= 0; --pos){
		if(buf[pos] == 1){
			for(int i=0; i!=2; ++i)
				for(int j=0; j!=2; ++j){
					new_pool[i][j] = 0;
					for(int k=0; k!=2; ++k)
						new_pool[i][j] += (old_pool[i][k] * old_pool[k][j]) % M;
				}
			normalize(new_pool, M);
			memcpy(old_pool, new_pool, sizeof(old_pool));

			for(int i=0; i!=2; ++i)
				for(int j=0; j!=2; ++j){
						new_pool[i][j] = 0;
					for(int k=0; k!=2; ++k)
						new_pool[i][j] += (old_pool[i][k] * base_pool[k][j]) % M;
				}
			normalize(new_pool, M);
			memcpy(old_pool, new_pool, sizeof(old_pool));
		}
		else{
			for(int i=0; i!=2; ++i)
				for(int j=0; j!=2; ++j){
						new_pool[i][j] = 0;
					for(int k=0; k!=2; ++k)
						new_pool[i][j] += (old_pool[i][k] * old_pool[k][j]) % M;
				}
			normalize(new_pool, M);
			memcpy(old_pool, new_pool, sizeof(old_pool));
		}
	}

	memcpy(result_pool, old_pool, sizeof(old_pool));
	dump_pool(result_pool);
}