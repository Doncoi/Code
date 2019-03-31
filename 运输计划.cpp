#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 300000;
const int MAX_ANS = 1e8 + 50;
const int MAX_LOG = 20; //math.log(300000, 2) = 18.194602975157967

const char endl = '\n';
struct FastIO {
	static const int BUFFER_SIZE = 1024 * 1024 * 64;
	char inBuf[BUFFER_SIZE], *pIn, outBuf[BUFFER_SIZE], *pOut;

	FastIO() {
		fetch();
		pOut = outBuf;
	}

	~FastIO() {
		flush();
	}

	void fetch() {
		fread(pIn = inBuf, 1, BUFFER_SIZE, stdin);
	}

	void flush() {
		fwrite(outBuf, 1, pOut - outBuf, stdout);
		pOut = outBuf;
	}

	char getchar() {
		if (pIn == inBuf + BUFFER_SIZE) fetch();
		return *pIn++;
	}

	void putchar(const char ch) {
		if (pOut == outBuf + BUFFER_SIZE) flush();
		*pOut++ = ch;
	}

	template <typename T>
	FastIO &operator>>(T &x) {
		x = 0;
		register char ch;
		register bool flag = false;
		while (ch = getchar(), !((ch >= '0' && ch <= '9') || ch == '-'));
		if (ch == '-') flag = true, ch = getchar();
		do x = x * 10 + ch - '0'; while (ch = getchar(), (ch >= '0' && ch <= '9'));
		if (flag) x = -x;
		return *this;
	}

	template <typename T>
	FastIO &operator<<(T x) {
		static char s[22];
		register int cnt = 0;
		register bool flag = (x < 0) ? (x = -x, true) : false;
		do s[cnt++] = x % 10; while (x /= 10);
		if (flag) putchar('-');
		while (cnt--) putchar(s[cnt] + '0');
		return *this;
	}

	FastIO &operator<<(const char ch) {
		putchar(ch);
		return *this;
	}
} io;

struct Node;
struct Edge;

int n, m, logn;
int f[MAXN + 1][MAX_LOG], g[MAXN + 1][MAX_LOG];

struct Node {
	int depth, pt;
	Edge *h;
	bool vis;

	Node (): depth(0), h(NULL), pt(0), vis(false) {}
} N[MAXN + 1];

struct Edge {
	Node *fr, *to; int w, times;
	Edge *ne;
    
    Edge() {}
	Edge (Node *fr, Node *to, int w): fr(fr), to(to), w(w), ne(fr->h), times(0) {}
} edges[(MAXN - 1) * 4];

struct Lca_Ans {
	int u, v, lca, ans;
} L[MAXN + 1]; int cnt;

void addEdge (int u, int v, int w) {
    static Edge *e = edges;
    
	N[u].h = &(*e++ = Edge(&N[u], &N[v], w));
	N[v].h = &(*e++ = Edge(&N[v], &N[u], w));
}

inline void bfs () {
	queue <Node *> q;
	N[1].depth = 1;
	q.push(&N[1]);
	f[1][0] = 1;
	g[1][0] = 0;

	Node *u;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		
		for (Edge *e = u->h; e != NULL; e = e->ne) {
			if (!e->to->depth) {
				e->to->depth = u->depth + 1;
				f[e->to - N][0] = u - N;
				g[e->to - N][0] = e->w;

				q.push(e->to);
			}
		}
	}
}

inline void prepare () {
	bfs();

	while ((1 << logn) <= n) logn ++;
	logn --;

	for (int j = 1; j <= logn; j++)
		for (int i = 1; i <= n; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
			g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1];
		}
}

inline int LCA (int u, int v) {
	L[cnt].u = u; L[cnt].v = v;

	int ans = 0;

	if (N[u].depth < N[v].depth) swap(u, v);

	if (N[u].depth > N[v].depth) {
		for (int j = logn; j >= 0; j--) {
			if (N[f[u][j]].depth >= N[v].depth) {
				ans += g[u][j];
				u = f[u][j];
			}
		}
	}

	if (u != v) {
		for (int j = logn; j >= 0; j--) {
			if (f[u][j] != f[v][j]) {
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

	L[cnt].lca = u; L[cnt].ans = ans;

	++cnt;

	return ans;
}

void debug() {
	for (int i = 0; i < cnt; i++) {
		printf("%d %d %d %d\n", L[i].u, L[i].v, L[i].lca, L[i].ans);
	}
}

int tot, ToBeDeleted;

inline void DFS (Node *x) {
	if (x->h == NULL) {
		return;
	}

	for (Edge *e = x->h; e != NULL; e = e->ne) {
		if (!e->to->vis) {
			e->to->vis = true;
			DFS(e->to);

			e->times += e->to->pt;
			x->pt += e->to->pt;
			if (e->times >= tot) {
				ToBeDeleted = max(ToBeDeleted, e->w);
			}

			e->to->pt = 0;
		}
	}
}

inline bool check (int limits) {
	int Max = 0; tot = 0; ToBeDeleted = 0;
	for (int i = 0; i < m; i++) {
		if (L[i].ans > limits) {
			Max = max(Max, L[i].ans);
			tot++;
			N[L[i].u].pt++; N[L[i].v].pt++;
			N[L[i].lca].pt -= 2;
		}
	}


	N[1].vis = true;
	DFS(&N[1]);

	for (int i = 1; i <= n; i++) {
		N[i].vis = false;
		for (Edge *e = N[i].h; e != NULL; e = e->ne) {
			e->times = 0;
		}
	}

	if (Max - ToBeDeleted > limits) return false;
	else return true;
}

int main () {
	io >> n >> m;
	for (int i = 1; i < n; i++) {
		int a, b, t;
		io >> a >> b >> t;
		addEdge(a, b, t);
		addEdge(b, a, t);
	}

	prepare();

	int MAX = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		io >> u >> v;
		MAX = max(MAX, LCA(u, v));
	}

    int ans = 0;
	int l = 0, r = MAX;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}

 	printf("%d\n", ans);
                                                                                  
	return 0;
}