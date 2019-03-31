#include <cstdio>
#include <cstring>
#include <queue> 
#include <algorithm>
#define MAXN 1005 
#define INF 0x3f3f3f3f

int map[MAXN][MAXN];
int pigs[MAXN], level[MAXN], k[MAXN]; //ÿ����Ȧ���������������ʱʹ�õľ��븨�����飬���㸨������
int n, m, s, t, tmp, num;

int bfs() {
	std :: queue<int> q;
	memset(level, -1, sizeof(level));
	level[t] = 0;

	q.push(t);
	while(!q.empty()) {
		int tmp = q.front();
		q.pop();
		for(int i = 0; i < n; ++ i) {
			if(level[i] == -1 && map[i][tmp]) {
				level[i] = level[tmp] + 1;
				q.push(i);
			}
		}

		if(tmp == s) {
			return 1;
		}
	}
	
	return 0;
}

int dfs(int x, int flow) {
	if(x == t) {
		return flow;
	}

	int tmp = flow;
	for(int i = 0; i < n && tmp; ++ i) {
		if(level[i] + 1 == level[x] && map[x][i]) {
			int rom = dfs(i, std :: min(flow, map[x][i]));
			map[x][i] -= rom;
			map[i][x] += rom;
			tmp -= rom;
		}
	}

	return flow - tmp;
}

int Dinic() {
	int cnt = 0;
	while(bfs()) {
		cnt += dfs(s, INF);
	}

	return cnt;
}

int main() {
	while(scanf("%d%d", &m, &n)) {
		memset(k, 0, sizeof(k));
		memset(map, 0, sizeof(map));

		for(int i = 1; i <= m; ++ i) {
			scanf("%d", &pigs[i]);
		}
		s = 0, t = n + 1;

		for(int i = 1; i <= n; ++ i) {
			scanf("%d", &tmp);
			for(int j = 1; j <= tmp; ++ j) {
				scanf("%d", &num);

				if(!k[num]) {
					map[s][i] += pigs[num];         //����㹹������
				} else {
					map[k[num]][i] = INF;    //����
				}

				k[num] = i;  //��¼����Ȧ����Ĺ˿�
			}

			scanf("%d", &map[i][t]);   //������ͨ����bian
		}

		n = t + 1;
		printf("%d\n", Dinic());
	}
}
