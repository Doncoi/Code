#include <cstdio>
#include <algorithm>
#include <queue>

const int MAXN = 50000;
const int MAXN_LOG = 16;
const int MAXM = 75000;

struct Node {
	struct Edge *e;
	int depth;
} N[MAXN];

struct Edge {
	Node *s, *t;
	int w;
	Edge *next;

	Edge(Node *s,Node * t,const int w) : s(s), t(t), w(w), next(s->e) {}
};

inline void addEdge(const int s,const int t,const int w) {
	N[s].e = new Edge(&N[s], &N[t], w);
	N[t].e = new Edge(&N[s], &N[t], w);
}

int n, f[MAXN][MAXN_LOG + 1], g[MAXN][MAXN_LOG + 1], logn;

inline void bfs() {
	std :: queue <Node *> q;
	q.push(&N[0]);
	N[0].depth = 1;
	f[0][0] = 0;
	g[0][0] = 0;

	while(!q.empty()) {
		Node *v = q.front();
		q.pop(); 

		for(Edge *e = v->e; e; e = e->next) {
			if(!e->t->depth) {
				e->t->depth = v->depth + 1;
				f[e->t - N][0] = v - N;
				g[e->t - N][0] = e->w;
				q.push(e->t);
			}
		}
	} 
}

inline void prepare() {
	bfs();

	while((1 << logn) <= n) logn ++;
	logn --;

	for(int j = 1; j <= logn; j ++) {
		for(int i = 0; i < n; i ++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
			g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1];
		}
	}
}

inline int query (int u, int v) {
	if(N[u].depth < N[v].depth) std :: swap(u, v);

	int ans = 0;

	if(N[u].depth > N[v].depth) {
		for(int j = logn; j >= 0; j --) {
			if(N[f[u][j]].depth >= N[v].depth) {
				ans += g[u][j];
				u = f[u][j];
			} 
		}
	}

	if(u != v) {
		for(int j = logn; j >= 0; j --) {
			if(f[u][j] != f[v][j]) {
				ans += g[u][j];
				ans += g[v][j];

				u = f[u][j];
				v = f[v][j];
			}
		}
		ans += g[u][0];
		ans += g[v][0];

		u = f[u][0];
	}

	return ans;
}

int main() {
	int m;
    scanf("%d",&n);
    for (int i = 0; i < n - 1; i++) {
    	int u, v, w;
    	scanf("%d %d %d", &u, &v, &w);
    	addEdge(u, v, w);
    }

    prepare();

    scanf("%d", &m);
    while(m --) {
    	int u, v;
    	scanf("%d %d", &u, &v);
    	printf("%d\n", query(u, v));
    }
	return 0;
}
