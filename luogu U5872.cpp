#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define MAXN 2005
#define INF 0x3f3f3f3

int n, m, ans;
int time[MAXN][MAXN];
int dis[MAXN];
bool visit[MAXN];

int dijstra() {
	std :: queue <int> q;
	q.push(n + 2);
	for(int i = 1;i <= n + 1;i ++) 
		dis[i] = INF;

	while(!q.empty()) {
		int tmp = q.front();
		printf("tmp: %d dis: %d\n", tmp, dis[tmp]);
		
		q.pop();
		visit[tmp] = true;
		if(tmp == n + 1) return dis[n + 1];
		for(int i = 1;i <= n + 1;i ++) { 
			if(time[tmp][i] && tmp != i) {
				if(!visit[i]) q.push(i);
				printf("to %d front: %d dis: %d\n", i, dis[i], dis[tmp] + time[tmp][i]);
				if(dis[tmp] + time[tmp][i] < dis[i])
					if(time[tmp][i] = -1) 
						dis[i] = dis[tmp] + time[tmp][i] + 1;
					else
				    	dis[i] = dis[tmp] + time[tmp][i]; 
			}
		}
	}

	return dis[n + 1];
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= m;i ++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		if(u == v) {
			time[u][n + 1] = -1;
			time[n + 2][u] = w;
		}
		time[u][v] = w;
	}   
    
    memset(dis, 0, sizeof(dis));
    memset(visit, false, sizeof(visit));
	ans = dijstra();
	
	for(int i = 1;i <= n + 2;i ++) 
		printf("%d ", dis[i]);
	
	printf("\n%d", ans);
} 


