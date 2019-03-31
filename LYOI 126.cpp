#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
#define MAXM 4000005
#define INF 0x7fffffff

int n, m;
std :: queue<int> q;

struct Node {
	int dis, vis;
} node[MAXM];

struct Pack {
	int q, c, k1, k2, timeCost;
} pack[MAXN];

inline int read() {
	int res = 0;  char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

inline void init() {
	char s[30];
	n = read(), m = read();
	for(int i = 1; i <= m; ++ i) {
		scanf("%d%s", &pack[i].timeCost, s);
		for(int j = 0; j < n; ++ j) 
			if(s[j] == '+') pack[i].q |= (1 << j);
			else if(s[j] == '-') pack[i].c |= (1 << j);

		scanf("%s", s);
		for(int j = 0; j < n; ++ j) 
			if(s[j] == '+') pack[i].k1 |= (1 << j);
			else if(s[j] == '-') pack[i].k2 |= (1 << j);
	}	

	n = (1 << n) - 1;
}

inline bool check(int x, int y) {
	return ( ((x | pack[y].q) == x) && !(x & pack[y].c) );
}

inline void SPFA() {
	for(int i = 0; i < MAXM; ++ i) 
		node[i].dis = 0x3f;
	q.push(n), node[n].dis = 0;

	while(!q.empty()) {
		int u = q.front(), v;  q.pop();  node[u].vis = 0;
		for(int i = 1; i <= m; ++ i) 
			if(check(u, i)) 
				if(node[v = ((u ^ (u & pack[i].k2)) | pack[i].k1)].dis > 
				  (node[u].dis + pack[i].timeCost)) {
					node[v].dis = node[u].dis + pack[i].timeCost;
					if(!node[v].vis) node[v].vis = 1, q.push(v);
				}
	}
}

inline void solve() {
	SPFA();
	if(node[0].dis != 0x3f3f3f3f) printf("%d\n", node[0].dis);
	else printf("0\n");
}

int main() {
	init();
	solve();
}
