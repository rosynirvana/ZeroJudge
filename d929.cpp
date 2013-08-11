#include <cstdio>
#include <cstring>

int main()
{
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i!=n; ++i){
			char buf[110];
			scanf("%s", buf);
			int last = strlen(buf) - 1;
			bool is_par = true;
			for(int j=0; j<=last; ++j, --last)
				if(buf[j] != buf[last]){
					is_par = false;
					break;
				}
			if(is_par)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}