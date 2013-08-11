#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

#define enqueue push


int map[2005][2005];
int dist[2005][2005];
void visit(int, int, queue< pair<int, int> >&);


int main()
{
	int N, M, x0, y0, x1, y1, K;
	while(scanf("%d %d %d %d %d %d %d", &N, &M, &x0, &y0, &x1, &y1, &K) == 7){
		for(int i=0; i<N; ++i){
			for(int j=0; j<M; ++j){
				map[i][j] = 0;
				if(j != 0)
					map[i][j] += 1;
				if(j != M-1)
					map[i][j] += 10;
				if(i != 0)
					map[i][j] += 100;
				if(i != N-1)
					map[i][j] += 1000;
			}
		}

		for(int i=1; i <=K; ++i){
			int x2, y2, x3, y3;
			scanf("%d %d %d %d", &x2, &y2, &x3, &y3);
			
			if(x2 == x3){
				map[x2][y2] -= 10;
				map[x3][y3] -= 1;
				
				int a = y2+1;
				int b = y3-1;
				while(a<=b){
					map[x2][a] -= 11;
					++a;
				}
			}
			if(y2 == y3){
				map[x2][y2] -= 1000;
				map[x3][y3] -= 100;
				
				int a = x2+1;
				int b = x3-1;
				while(a<=b){
					map[a][y2] -= 1100;
					++a;
				}
				
			}
		}

		memset(dist, 0, sizeof(dist));
		dist[x0][y0] = 0;
		queue< pair<int, int> > q;
		q.enqueue(make_pair(x0, y0));
		while(!q.empty()){
			pair<int, int> point = q.front();
			if(point.first == x1 && point.second == y1)
				break;
			q.pop();
			visit(point.first, point.second, q);
		}

		if(dist[x1][y1] == 0)
			printf("%d\n", 10080);
		else
			printf("%d\n", dist[x1][y1]);

	}
}

void visit(int y, int x, queue< pair<int, int> >& q)
{
	if(map[y][x] < 10000){
		int temp = map[y][x];
		map[y][x] += 10000;
		if(temp % 10 == 1){
			q.enqueue(make_pair(y, x-1));
			dist[y][x-1] = dist[y][x]+1;
		}
		temp /= 10;
		if(temp % 10 == 1){
			q.enqueue(make_pair(y, x+1));
			dist[y][x+1] = dist[y][x]+1;
		}
		temp /= 10;
		if(temp % 10 == 1){
			q.enqueue(make_pair(y-1, x));
			dist[y-1][x] = dist[y][x]+1;
		}
		temp /= 10;
		if(temp == 1){
			q.enqueue(make_pair(y+1, x));
			dist[y+1][x] = dist[y][x]+1;
		}
	}
}