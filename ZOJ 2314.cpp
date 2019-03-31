#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF (1 << 30)
#define MAXN 222
#define MAXM 222 * 444

int n, m, T;
int s, t, cnt, NV;
int head[MAXN], level[MAXN], gap[MAXN];
int pre[MAXN], cur[MAXN];

struct Edge {
	int cap, flow, to, next;
} edge[MAXM];

void addEdge(int from, int to, int cap) {
	edge[cnt].to = to, edge[cnt].cap = cap, edge[cnt].flow = 0; 
	edge[cnt].next = head[from], head[from] = cnt ++;

	edge[cnt].to = from, edge[cnt].cap = 0, edge[cnt].flow = 0;
	edge[cnt].next = head[to], head[to] = cnt ++;
}

void bfs() {          //Ԥ������ͼ
	memset(level, -1, sizeof(level));
	memset(gap, 0, sizeof(gap));
	level[t] = 0, gap[level[t]] ++;
	std :: queue<int> q;    q.push(t);

	while(!q.empty()) {
		int u = q.front();    q.pop();
		for(int e = head[u]; e != -1; e = edge[e].next) {
			int v = edge[e].to;
			if(level[v] != -1) continue;
			else level[v] = level[u] + 1, gap[level[v]] ++, q.push(v);
		}
	}
}

int ISAP() {
	bfs();
	memset(pre, -1, sizeof(pre));    //ǰ�������ڷ���׷��
	memcpy(cur, head, sizeof(head));    //���ڴ��������ϵ
	int u = pre[s] = s, flow = 0, aug = INF;
	gap[0] = NV;


	while(level[s] < NV) {
		bool flag = false;

		for(int &e = cur[u]; e != -1; e = edge[e].next) {
			int v = edge[e].to;

			if(edge[e].cap != edge[e].flow && level[u] == level[v] + 1) {    //ǰ��
				flag = true, pre[v] = u, u = v, aug = std :: min(aug, edge[e].cap - edge[e].flow);

				if(v == t) {    //�����㣬����
					flow += aug;
					for(u = pre[v]; v != s; v = u, u = pre[u]) {    //���ݣ���������   
						edge[cur[u]].flow += aug;
						edge[cur[u] ^ 1].flow -= aug;
					}

					aug = INF;
				}

				break;
			}
		}

		if(flag) continue;
		int minLevel = NV;
		for(int e = head[u]; e != -1; e = edge[e].next) {    //�͵ظ��¾����ϵ
			int v = edge[e].to;
			if(edge[e].cap != edge[e].flow && level[v] < minLevel) {
				minLevel = level[v], cur[u] = e;
			}
		}

		if(-- gap[level[u]] == 0) break;    //GAP�Ż�
		level[u] = minLevel + 1; gap[level[u]] ++; u = pre[u];    //��������·��ִ��retreat�����Ի���һ��
	} 

	return flow;
}

int low[MAXM], d[MAXN];
int main() {
	scanf("%d", &T);
	while(T --) {
		scanf("%d %d", &n, &m);
		memset(d, 0, sizeof(d));
		s = 0, t = n + 1, NV = t + 1, cnt = 0;
		memset(head, -1, sizeof(head));

		for(int i = 0; i < m; ++ i) {
			int from, to, cap;
			scanf("%d%d%d%d", &from, &to, low + i, &cap);
			addEdge(from, to, cap - low[i]);
			d[from] += low[i], d[to] -= low[i];
		}

		int tot = 0;    //��¼�������������
		for(int i = 1; i <= n; ++ i) {
			if(d[i] < 0) addEdge(s, i, -d[i]);    //M(i) < 0����������
			else addEdge(i, t, d[i]), tot += d[i];     //M(i) > 0, ��������
		}

		if(ISAP() != tot) {    //���û������
			printf("NO\n");
		} else {    //�������п���������
			printf("YES\n");
			for(int i = 0; i < m; ++ i) {
				printf("%d\n", edge[i << 1].flow + low[i]);
			}
		}
	}

	return 0;
}
